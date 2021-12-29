#include <bits/stdc++.h>
using namespace std;

// burrow entrances from hallway
const vector<int> burrow_entrance{0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 0};
const int oo = 9999999;
const int A = 1;
const int B = 2;
const int C = 3;
const int D = 4;

struct hash_pair {
  size_t operator()(const pair<uint64_t, uint64_t>& p) const {
    auto hash1 = hash<uint64_t>{}(p.first);
    auto hash2 = hash<uint64_t>{}(p.second);
    return hash1 ^ hash2;
  }
};

typedef pair<uint64_t, uint64_t> node_t;
typedef unordered_map<node_t, set<pair<node_t, int>>, hash_pair> adj_t;
typedef vector<vector<int>> burrows_t;
typedef tuple<uint64_t, uint64_t, int> encoded_t;

struct state_t {
  vector<int> hallway;
  burrows_t burrows;
  int energy;

  state_t() : hallway(11, 0), burrows(4, vector<int>(4, 0)),
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

encoded_t encode_state(const state_t& s) {
  // 48 bits for the burrows
  uint64_t burrows = 0;
  for (int i = 0; i < 4; i++) {
    uint64_t b = (s.burrows[i][3] << 9) //
        | (s.burrows[i][2] << 6) //
        | (s.burrows[i][1] << 3) //
        | s.burrows[i][0];
    burrows |= b << (12 * i);
  }
  // first 33 bits for the hallway
  uint64_t hallway = 0;
  for (int i = 0; i < 11; i++)
    hallway |= static_cast<uint64_t>(s.hallway[i]) << (3 * i);
  return {burrows, hallway, s.energy};
}

state_t decode_state(const encoded_t& encoded) {
  auto [burrows, hallway, energy] = encoded;
  state_t s;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      s.burrows[i][j] = static_cast<int>(burrows & 7);
      burrows >>= 3;
    }
  }
  for (int i = 0; i < 11; i++) {
    s.hallway[i] = static_cast<int>(hallway & 7);
    hallway >>= 3;
  }
  s.energy = energy;
  return s;
}

state_t decode_state(const node_t& node) {
  return decode_state({node.first, node.second, 0});
}

node_t to_node(const state_t& s) {
  auto encoded = encode_state(s);
  return {get<0>(encoded), get<1>(encoded)};
}

void check_burrow_and_move(const state_t& s, int burrow_index, int amphipod,
                           int hallway_pos, int current_pos,
                           vector<encoded_t>& moves) {
  // before checking if there's room, see if the neighbours are the same type
  for (int k = 0; k < 4; k++) {
    int bi = s.burrows[burrow_index][k];
    if (bi) {
      if (bi != amphipod) return;
      continue;
    }
    // can move here
    auto ss = s;
    ss.hallway[hallway_pos] = 0; // not in the hallway anymore
    ss.burrows[burrow_index][k] = amphipod;
    // descended 4 - k steps
    ss.energy = energy(amphipod, abs(hallway_pos - current_pos) + 4 - k);
    moves.push_back(encode_state(ss));
    return;
  }
}

void check_hallway_and_move(int amphipod, int burrow_index, int burrow_level,
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
    ss.burrows[burrow_index][burrow_level] = 0; // the burrow is now empty
    ss.hallway[j] = amphipod;
    ss.energy = energy(amphipod, abs(j - hallway_pos) + 4 - burrow_level);
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
    ss.burrows[burrow_index][burrow_level] = 0; // the burrow is now empty
    ss.hallway[j] = amphipod;
    ss.energy = energy(amphipod, abs(j - hallway_pos) + 4 - burrow_level);
    moves.push_back(encode_state(ss));
  }
}

vector<encoded_t> possible_moves_from(const state_t& s) {
  vector<encoded_t> moves;
  // ------ check amphipods in the hallway first ------
  for (int i = 0; i < 11; i++) {
    if (!s.hallway[i]) continue;
    int amphipod = s.hallway[i];
    // look right
    for (int j = i + 1; j < 11; j++) {
      // found someone here, can't advance further
      if (s.hallway[j]) break;
      // found a burrow along the way
      if (int b = burrow_entrance[j]; b == amphipod)
        check_burrow_and_move(s, --b, amphipod, i, j, moves);
    }

    // look left
    for (int j = i - 1; j >= 0; j--) {
      // found someone here, can't advance further
      if (s.hallway[j]) break;
      // found a burrow along the way
      if (int b = burrow_entrance[j]; b == amphipod)
        check_burrow_and_move(s, --b, amphipod, i, j, moves);
    }
  }

  // ------ check amphipods in burrows --------
  for (int i = 0; i < 4; i++) {
    // position in the hallway of this burrow
    int hallway_pos = 2 * (i + 1);

    // check burrows from bottom to the top
    for (int j = 0; j < 4; j++) {
      int amphipod = s.burrows[i][j];
      if (amphipod && (j == 3 || !s.burrows[i][j + 1])) {
        check_hallway_and_move(amphipod, i, j, hallway_pos, s, moves);
        break;
      }
    }
  }

  return moves;
}

adj_t gen_adjacency_list(const state_t& start) {
  adj_t adj;
  queue<node_t> q; q.push(to_node(start));
  unordered_set<node_t, hash_pair> processed;
  while (!q.empty()) {
    auto node = q.front(); q.pop();
    if (processed.count(node)) continue;
    processed.insert(node);

    auto state = decode_state(node);
    for (auto move : possible_moves_from(state)) {
      node_t child_node{get<0>(move), get<1>(move)};
      int energy = get<2>(move);
      adj[node].insert({child_node, energy});
      q.push(child_node);
    }
  }
  return adj;
}

int main() {
#define S start.burrows
  state_t start;
  S[0][3] = D; S[1][3] = B; S[2][3] = A; S[3][3] = C;
  S[0][2] = D; S[1][2] = C; S[2][2] = B; S[3][2] = A;
  S[0][1] = D; S[1][1] = B; S[2][1] = A; S[3][1] = C;
  S[0][0] = C; S[1][0] = A; S[2][0] = D; S[3][0] = B;
  // S[0][3] = B; S[1][3] = C; S[2][3] = B; S[3][3] = D;
  // S[0][2] = D; S[1][2] = C; S[2][2] = B; S[3][2] = A;
  // S[0][1] = D; S[1][1] = B; S[2][1] = A; S[3][1] = C;
  // S[0][0] = A; S[1][0] = D; S[2][0] = C; S[3][0] = A;
  node_t start_node = to_node(start);
#undef S

#define S finish.burrows
  state_t finish;
  S[0][3] = A; S[1][3] = B; S[2][3] = C; S[3][3] = D;
  S[0][2] = A; S[1][2] = B; S[2][2] = C; S[3][2] = D;
  S[0][1] = A; S[1][1] = B; S[2][1] = C; S[3][1] = D;
  S[0][0] = A; S[1][0] = B; S[2][0] = C; S[3][0] = D;
  node_t finish_node = to_node(finish);
#undef S

  cout << "generating adjacency list...\n";
  auto t1 = std::chrono::high_resolution_clock::now();
  adj_t adj = gen_adjacency_list(start);
  auto t2 = std::chrono::high_resolution_clock::now();
  cout << "took: " << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() << " s" << endl;
  cout << "# nodes: " << adj.size() << endl;

  cout << "initializing energy map" << endl;
  t1 = std::chrono::high_resolution_clock::now();
  unordered_map<node_t, int, hash_pair> energies;
  unordered_map<node_t, bool, hash_pair> processed;
  unordered_map<node_t, node_t, hash_pair> parents;
  for (auto [node, edges] : adj) {
    energies[node] = oo;
    processed[node] = false;
  }
  t2 = std::chrono::high_resolution_clock::now();
  cout << "took: " << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() << " s" << endl;

  cout << "dijkstra" << endl;
  t1 = std::chrono::high_resolution_clock::now();
  energies[start_node] = 0;
  priority_queue<pair<int, node_t>> q;
  q.push({0, start_node});
  while (!q.empty()) {
    auto node = q.top().second; q.pop();
    if (processed[node]) continue;
    processed[node] = true;
    for (auto [child_node, child_energy] : adj[node])
      if (energies[node] + child_energy < energies[child_node]) {
        energies[child_node] = energies[node] + child_energy;
        q.push({-energies[child_node], child_node});
        parents[child_node] = node;
      }
  }
  t2 = std::chrono::high_resolution_clock::now();
  cout << "took: " << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() << " s" << endl;
  cout << "min energy found: " << energies[finish_node] << '\n';

  return 0;
}