#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>

template<typename Type> 
std::vector< std::vector<Type> > createTable(const size_t numRows, const size_t numCols, Type defaultValue = Type()) { 
   std::vector< std::vector<Type> > table;
   for (size_t i = 0; i < numRows; ++i)
      table.push_back(std::vector<Type>(numCols, defaultValue));
   return table;
}

struct board {
   int w, h;
   int gx, gy;
   int sx, sy;   
   std::vector< std::vector<char> > table;
   
   board(int w, int h) : w(w), h(h), table(createTable<char>(w, h)) {  }
   
   // Copy another board data and attributes
   board(const board& b) : w(b.w), h(b.h), gx(b.gx), gy(b.gy), sx(b.sx), sy(b.sy), table(createTable<char>(w, h)) {
      for (int y = 0; y < h; y++)
         for (int x = 0; x < w; x++)
            table[x][y] = b.table[x][y];
   }
   
   void read(std::istream& is) {
      for (int y = 0; y < h; y++) {
         std::string line;
         std::getline(is, line, '\n');
         for (int x = 0; x < w; x++) {
            table[x][y] = line[x];
            if (table[x][y] == 'G') {
               gx = x; gy = y;
            }
            if (table[x][y] == 'S') {
               sx = x; sy = y;
            }
         }
      }
   }
   bool inside(int x, int y) const {
      return x >= 0 && x < w && y >= 0 && y < h;
   }
   int clamp(int v, int l) const {
      return v >= l - 1 ? l - 1 : (v < 0 ? 0 : v);
   }
   int clampW(int x) const { 
      return clamp(x, w);
   }
   int clampH(int y) const { 
      return clamp(y, h);
   }
};

std::ostream& operator<<(std::ostream& os, const board& b) {
	for (int y = 0; y < b.h; y++) { 
		for (int x = 0; x < b.w; x++)
			os << b.table[x][y];
		os << std::endl;
	}
	return os;
}

struct state {
   enum DIR { UP, RIGHT, DOWN, LEFT, LAST };
   static int dirY[4];
   static int dirX[4];  
   
   board* original;
   int px, py, step;
   float eval;
   
   state(board* b, int px, int py, int step) : original(b), px(px), py(py), step(step) { }

   int id() const {
      return (py * original->w + px) * 10 + (step % 4);
   } 
   bool operator==(const state& state) const {
      return id() == state.id();
   }
   bool operator<(const state& state) const {
      return eval > state.eval;
   }   
   static char getLaserChar(DIR d) {
      switch (d) {
         case UP: return '^';
         case RIGHT: return '>';
         case DOWN: return 'v';
         case LEFT: return '<';
         default: return 0;
      }
   }   
   
   static bool oppositeDirs(DIR d1, DIR d2) {
      return d1 != d2 && (d1 & 1) == (d2 & 1);
   }
   
   static DIR getLaserDir(char c) {
      switch (c) {
         case '^': return UP;
         case '>': return RIGHT;
         case 'v': return DOWN;
         case '<': return LEFT;
      }
      return LAST;
   }   
   
   bool isLaser(char c) const {
      return c == '^' || c == '>' || c == 'v' || c == '<';
   }
   static bool isEmpty(char c) {
      return c == '.' || c == 'G' || c == 'S';
   }   
   char rotateLaser(char c) const { 
      return getLaserChar( static_cast<DIR>((getLaserDir(c) + step) % 4) );
   }
   float evaluate() {
      board b = apply();
      // Check if we are dead 
      // 
      // We cannot be dead in the first state
      if (step > 0) { 
         for (int d = 0; d < DIR::LAST; d++) {
            int ox = dirX[d];
            int oy = dirY[d];
            int x = px + ox;
            int y = py + oy;
            while (b.inside(x, y)) {
               char c = b.table[x][y];
               if (isLaser(c) && oppositeDirs(static_cast<DIR>(d), getLaserDir(c))) return -1.0f;
               if (!isEmpty(c)) break;
               x += ox;
               y += oy;
            }
         }
      }
      int dx = original->gx - px;
      int dy = original->gy - py;
      eval = std::sqrt(static_cast<float>(dx * dx + dy * dy));
      return eval;
   }
   board apply() const {
      board cb(*original);
      for (int y = 0; y < cb.h; y++)
         for (int x = 0; x < cb.w; x++) {
            char c = cb.table[x][y];
            if (isLaser(c)) {
               char r = rotateLaser(c);
               cb.table[x][y] = r;
            }
         }
      return cb;
   }
   std::vector<state> getChildren() {
      board b = apply();
      std::vector<state> children;

      // b.table[px][py] = 'O';
      // std::cout << b << std::endl;
      // b.table[px][py] = '.';
      // _getch();

      for (int d = 0; d < DIR::LAST; d++) {
         int ox = dirX[d];
         int oy = dirY[d];
         int x = px + ox;
         int y = py + oy;
         if (b.inside(x, y)) {
            char c = b.table[x][y];
            if (isEmpty(c)) {
               state child(original, x, y, step + 1);
               if (child.evaluate() >= 0.0f) children.push_back(child);
            }
         }
      }
      return children;
   }
};

int state::dirX[4] = {  0,  1,  0, -1};
int state::dirY[4] = { -1,  0,  1,  0};

int solve(board& board) { 
   std::vector<state> open;
   std::set<int> closed;
   open.push_back(state(&board, board.sx, board.sy, 0));
   while (!open.empty()) {
      state node = open.front();
      std::pop_heap(open.begin(), open.end());
      open.pop_back();
      
      if (node.px == board.gx && node.py == board.gy) return node.step; 
      if (closed.count(node.id()) != 0) continue;

      closed.insert(node.id());
      // Generate moves
      std::vector<state> moves = node.getChildren();
      for (auto move : moves)
         if (closed.count(move.id()) == 0) {
            open.push_back(move); 
            std::push_heap(open.begin(), open.end());
         }
   }
   return -1;
}

board createBoardFromInput(std::istream& fis) {
   int h, w;
   fis >> h >> w;
   fis.ignore(256, '\n');
   board b(w, h);
   b.read(fis);
   return b;
}

int Q_main(int argc, char* argv[]) {
    std::ifstream fis("laser_maze.in");
    std::ofstream fos("laser_maze.out");
    std::cout.rdbuf(fos.rdbuf());

    int t;
    fis >> t;
    fis.ignore(256, '\n');

    int cases = 1;
    while (t--) { 
      board b = createBoardFromInput(fis);
      int steps;
      steps = solve(b);
      std::cout << "Case #" << cases << ": ";
      if (steps > 0) {
         std::cout << steps;
      } else {
         std::cout << "impossible";
      }
      std::cout << std::endl;
      cases++;
    }
    return 0;
}
