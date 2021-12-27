#include <chrono>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <utility>

using namespace std;
// burrow entrances from hallway
const vector<int> burrow_entrance{0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 0};
const int oo = 9999999;
const int A = 1;
const int B = 2;
const int C = 3;
const int D = 4;

typedef unordered_map<int64_t, set<pair<int64_t, int>>> adj_t;
typedef vector<vector<int>> burrows_t;
typedef pair<int64_t, int> encoded_t;

struct state_t {
  vector<int> hallway;
  burrows_t burrows;
  int energy;

  state_t() : hallway(11, 0), burrows(4, vector<int>(2, 0)),
      energy(0) {}
};

int energy(int amphipod, int steps) {
  switch (amphipod) {
    case 1: return steps;
    case 2: return steps * 10;
    case 3: return steps * 100;
    default: return steps * 1000;
  }
}

bool operator==(const state_t& s1, const state_t& s2) {
  //if (s1.energy != s2.energy) return false;
  for (int i = 0; i < 11; i++)
    if (s1.hallway[i] != s2.hallway[i]) return false;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 2; j++)
      if (s1.burrows[i][j] != s2.burrows[i][j]) return false;
  return true;
}

encoded_t encode_state(const state_t& s) {
  // first 24 bits for the burrows
  int64_t burrows = 0;
  for (int i = 0; i < 4; i++)
    burrows |= (((s.burrows[i][1] << 3) | s.burrows[i][0]) << (6 * i));
  // remaining 33 bits for the hallway
  int64_t hallway = 0;
  for (int i = 0; i < 11; i++)
    hallway |= static_cast<int64_t>(s.hallway[i]) << (3 * i);
  return {(hallway << 24) | burrows, s.energy};
}

state_t decode_state(const encoded_t& encoded) {
  auto [bh, energy] = encoded;
  state_t s;
  for (int i = 0; i < 4; i++) {
    s.burrows[i][0] = static_cast<int>(bh & 7);
    bh >>= 3;
    s.burrows[i][1] = static_cast<int>(bh & 7);
    bh >>= 3;
  }
  for (int i = 0; i < 11; i++) {
    s.hallway[i] = static_cast<int>(bh & 7);
    bh >>= 3;
  }
  s.energy = energy;
  return s;
}

string to_str(const state_t& s) {
  ostringstream o;
  o << "#############\n#";
  for (int i = 0; i < 11; i++)
    o << static_cast<char>(s.hallway[i] ? s.hallway[i] - 1 + 'A' : '.');
  o << "#\n###";
  for (int i = 0; i < 4; i++) {
    o << static_cast<char>(s.burrows[i][1] ? s.burrows[i][1] - 1 + 'A' : '.');
    o << '#';
  }
  o << "##     energy: " << s.energy << " id: " << encode_state(s).first << "\n  #";
  for (int i = 0; i < 4; i++) {
    o << static_cast<char>(s.burrows[i][0] ? s.burrows[i][0] - 1 + 'A' : '.');
    o << '#';
  }
  o << "\n  #########\n";
  return o.str();
}

void check_burrow_and_move(const state_t& s, int burrow_index, int amphipod,
                           int hallway_pos, int current_pos,
                           vector<encoded_t>& moves) {
  // check if is totally empty
  if (!s.burrows[burrow_index][0]) {
    // can move here
    auto ss = s;
    ss.hallway[hallway_pos] = 0; // not in the hallway anymore
    ss.burrows[burrow_index][0] = amphipod;
    // descended 2 steps
    ss.energy = energy(amphipod, abs(hallway_pos - current_pos) + 2);
    moves.push_back(encode_state(ss));
  }
  // if is partially empty and the neighbour is the same type
  if (!s.burrows[burrow_index][1] && s.burrows[burrow_index][0] == amphipod) {
    // can move here
    auto ss = s;
    ss.hallway[hallway_pos] = 0; // not in the hallway anymore
    ss.burrows[burrow_index][1] = amphipod;
    // descended 1 step
    ss.energy = energy(amphipod, abs(hallway_pos - current_pos) + 1);
    moves.push_back(encode_state(ss));
  }
}

void check_hallway_and_move(int amphipod, int burrow_index, int burrow_depth,
                            int hallway_pos, const state_t& current_state,
                            vector<encoded_t>& moves) {
  // look right
  for (int j = hallway_pos + 1; j < 11; j++) {
    // found someone here, won't be able to advance any further
    if (current_state.hallway[j]) break;
    // ignore burrow entrances
    if (burrow_entrance[j]) continue;
    // otherwise, is empty, they can move here
    auto ss = current_state;
    ss.burrows[burrow_index][2 - burrow_depth] = 0; // the burrow is now empty
    ss.hallway[j] = amphipod;
    ss.energy = energy(amphipod, abs(j - hallway_pos) + burrow_depth);
    moves.push_back(encode_state(ss));
  }
  // look left
  for (int j = hallway_pos - 1; j >= 0; j--) {
    // found someone here, won't be able to advance any further
    if (current_state.hallway[j]) break;
    // ignore burrow entrances
    if (burrow_entrance[j]) continue;
    // empty, we can move here
    auto ss = current_state;
    ss.burrows[burrow_index][2 - burrow_depth] = 0; // the burrow is now empty
    ss.hallway[j] = amphipod;
    ss.energy = energy(amphipod, abs(j - hallway_pos) + burrow_depth);
    moves.push_back(encode_state(ss));
  }
}

vector<encoded_t> possible_moves_from(const state_t& s) {
  vector<encoded_t> moves;
  // ------ check hallway first ------
  for (int i = 0; i < 11; i++) {
    if (!s.hallway[i]) continue;
    int amphipod = s.hallway[i];
    // look right
    for (int j = i + 1; j < 11; j++) {
      // found someone here, can't advance further
      if (s.hallway[j]) break;
      // found a burrow along the way
      if (int b = burrow_entrance[j]; b--)
        check_burrow_and_move(s, b, amphipod, i, j, moves);
    }

    // look left
    for (int j = i - 1; j >= 0; j--) {
      // found someone here, can't advance further
      if (s.hallway[j]) break;
      // found a burrow along the way
      if (int b = burrow_entrance[j]; b--)
        check_burrow_and_move(s, b, amphipod, i, j, moves);
    }
  }

  // ------ check burrows --------
  for (int i = 0; i < 4; i++) {
    // position in the hallway of this burrow
    int hallway_pos = 2 * (i + 1);

    // check the bottom first and see if they can move to the hallway
    int amphipod = s.burrows[i][0];
    if (amphipod && !s.burrows[i][1])
      check_hallway_and_move(amphipod, i, 2, hallway_pos, s, moves);

    // check the top one
    amphipod = s.burrows[i][1];
    if (amphipod)
      check_hallway_and_move(amphipod, i, 1, hallway_pos, s, moves);
  }

  return moves;
}

string _d(int64_t s) {
  return to_str(decode_state({s, 0}));
}

adj_t gen_adjacency_list(const state_t& start) {
  adj_t adj;
  queue<encoded_t> q; q.push(encode_state(start));
  set<int64_t> processed;
  while (!q.empty()) {
    auto encoded = q.front(); q.pop();
    if (processed.count(encoded.first)) continue;
    processed.insert(encoded.first);
    auto state = decode_state(encoded);
    for (auto move : possible_moves_from(state)) {
      adj[encoded.first].insert(move);
      q.push(move);
    }
  }
  return adj;
}

int main() {
  state_t start;
#define S start.burrows
  S[0][1] = B; S[1][1] = C; S[2][1] = B; S[3][1] = D;
  S[0][0] = A; S[1][0] = D; S[2][0] = C; S[3][0] = A;
  cout << to_str(start) << endl;
#undef S

  state_t finish;
#define S finish.burrows
  S[0][1] = A; S[1][1] = B; S[2][1] = C; S[3][1] = D;
  S[0][0] = A; S[1][0] = B; S[2][0] = C; S[3][0] = D;
#undef S

  state_t tmp;
#define S tmp.burrows
  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[3] = B;
  S[0][1] = B; S[1][1] = C; S[2][1] = 0; S[3][1] = D;
  S[0][0] = A; S[1][0] = D; S[2][0] = C; S[3][0] = A;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[3] = B; tmp.hallway[5] = C;
  S[0][1] = B; S[1][1] = 0; S[2][1] = 0; S[3][1] = D;
  S[0][0] = A; S[1][0] = D; S[2][0] = C; S[3][0] = A;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[3] = B;
  S[0][1] = B; S[1][1] = 0; S[2][1] = C; S[3][1] = D;
  S[0][0] = A; S[1][0] = D; S[2][0] = C; S[3][0] = A;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[3] = B; tmp.hallway[5] = D;
  S[0][1] = B; S[1][1] = 0; S[2][1] = C; S[3][1] = D;
  S[0][0] = A; S[1][0] = 0; S[2][0] = C; S[3][0] = A;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[5] = D;
  S[0][1] = B; S[1][1] = 0; S[2][1] = C; S[3][1] = D;
  S[0][0] = A; S[1][0] = B; S[2][0] = C; S[3][0] = A;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[3] = B; tmp.hallway[5] = D;
  S[0][1] = 0; S[1][1] = 0; S[2][1] = C; S[3][1] = D;
  S[0][0] = A; S[1][0] = B; S[2][0] = C; S[3][0] = A;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[5] = D;
  S[0][1] = 0; S[1][1] = B; S[2][1] = C; S[3][1] = D;
  S[0][0] = A; S[1][0] = B; S[2][0] = C; S[3][0] = A;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[5] = D; tmp.hallway[7] = D;
  S[0][1] = 0; S[1][1] = B; S[2][1] = C; S[3][1] = 0;
  S[0][0] = A; S[1][0] = B; S[2][0] = C; S[3][0] = A;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[5] = D; tmp.hallway[7] = D; tmp.hallway[9] = A;
  S[0][1] = 0; S[1][1] = B; S[2][1] = C; S[3][1] = 0;
  S[0][0] = A; S[1][0] = B; S[2][0] = C; S[3][0] = 0;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[5] = D; tmp.hallway[9] = A;
  S[0][1] = 0; S[1][1] = B; S[2][1] = C; S[3][1] = 0;
  S[0][0] = A; S[1][0] = B; S[2][0] = C; S[3][0] = D;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  tmp.hallway[9] = A;
  S[0][1] = 0; S[1][1] = B; S[2][1] = C; S[3][1] = D;
  S[0][0] = A; S[1][0] = B; S[2][0] = C; S[3][0] = D;
  cout << to_str(tmp) << endl;

  fill(begin(tmp.hallway), end(tmp.hallway), 0);
  S[0][1] = A; S[1][1] = B; S[2][1] = C; S[3][1] = D;
  S[0][0] = A; S[1][0] = B; S[2][0] = C; S[3][0] = D;
  cout << to_str(tmp) << endl;
#undef S

  cout << "generating adjacency list...\n";
  auto t1 = std::chrono::high_resolution_clock::now();
  adj_t adj = gen_adjacency_list(start);
  auto t2 = std::chrono::high_resolution_clock::now();
  cout << "took: " << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() << " s" << endl;
  cout << "# nodes: " << adj.size() << endl;

  unordered_map<int64_t, int> energies;
  for (auto [node, edged] : adj)
    energies[node] = oo;

  auto start_node = encode_state(start).first;
  energies[start_node] = 0;
  unordered_set<bool> processed;
  priority_queue<pair<int, int64_t>> q;
  q.push({0, start_node});
  while (!q.empty()) {
    auto [energy, node] = q.top(); q.pop();
    if (processed.count(node)) continue;
    processed.insert(node);
    for (auto [child_node, child_energy] : adj[node])
      if (energies[node] + child_energy < energies[child_node]) {
        //cout << "here " << (energies[node] + child_energy) << endl;
        energies[child_node] = energies[node] + child_energy;
        q.push({-energies[child_node], child_node});
      }
  }
  cout << "tmp: " << energies[encode_state(tmp).first] << endl;
  cout << "min energy found: " << energies[encode_state(finish).first] << '\n';
  return 0;
}