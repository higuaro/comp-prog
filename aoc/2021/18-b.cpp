#include <bits/stdc++.h>
using namespace std;
struct node_t {
  int value;
  node_t* parent;
  node_t* left;
  node_t* right;
  node_t() : value(-1), parent(nullptr), left(nullptr), right(nullptr) {}
  node_t(int value, node_t* parent) : value(value), parent(parent),
      left(nullptr), right(nullptr) {}
};

string to_str(const node_t* node) {
  if (node == nullptr) return "";
  if (node->value != -1) return to_string(node->value);
  return "[" + to_str(node->left) + "," + to_str(node->right) + "]";
}

node_t* parse_node(const string& number, int& i) {
  if (i >= number.size()) return nullptr;
  char c = number[i++];
  node_t* node = new node_t;
  if (c == '[') {
    auto* left = parse_node(number, i);
    left->parent = node;
    node->left = left;
    i++;
    auto* right = parse_node(number, i);
    right->parent = node;
    node->right = right;
    i++;
  } else {
    assert(isdigit(c));
    node->value = c - '0';
  }
  return node;
}

node_t* sum(node_t* n1, node_t* n2) {
  auto* result = new node_t;
  result->left = n1;
  result->right = n2;
  n1->parent = result;
  n2->parent = result;
  return result;
}

void split(node_t* n) {
  auto* l = new node_t(n->value / 2, n);
  auto* r = new node_t((n->value + 1) / 2, n);
  l->parent = n;
  r->parent = n;
  n->value = -1;
  n->left = l;
  n->right = r;
}

node_t* first_node(node_t* n, unordered_set<node_t*>& visited, bool prefer_left) {
  if (!n || visited.count(n)) return nullptr;
  if (n->value != -1) return n;
  auto* f = first_node(prefer_left ? n->left : n->right, visited, prefer_left);
  if (f) return f;
  return first_node(prefer_left ? n->right : n->left, visited, prefer_left);
}

node_t* find_first(node_t* n, bool is_left) {
  unordered_set<node_t*> visited{n};
  n = n->parent;
  while (n && visited.count(is_left ? n->left : n->right)) {
    visited.insert(n);
    n = n->parent;
  }
  return first_node(n, visited, !is_left);
}

void explode(node_t* n) {
  if (n->value != -1) n = n->parent;
  int l = n->left->value;
  int r = n->right->value;
  n->value = 0;
  delete n->left;  n->left = nullptr;
  delete n->right; n->right = nullptr;
  auto* first_left = find_first(n, true);
  if (first_left) first_left->value += l;
  auto* first_right = find_first(n, false);
  if (first_right) first_right->value += r;
}

bool explode_nodes(node_t* n, int level = 0) {
  if (n == nullptr) return false;
  bool changed = false;
  if (n->value == -1) {
    if (level >= 4 && n->left->value != -1 && n->right->value != -1) {
      explode(n);
      changed = true;
    } else {
      changed = explode_nodes(n->left, level + 1);
      if (changed) return changed;
      changed = explode_nodes(n->right, level + 1);
      if (changed) return changed;
    }
  } 
  return changed;
}

bool split_nodes(node_t* n) {
  if (n == nullptr) return false;
  if (n->value >= 10) {
    split(n);
    return true;
  }
  return split_nodes(n->left) || split_nodes(n->right);
}

void reduce(node_t* n) {
  while (explode_nodes(n) || split_nodes(n))
    cout << "-> " << to_str(n) << '\n';
}

int magnitude(node_t* n) {
  if (!n) return 0;
  if (n->value != -1) return n->value;
  return 3 * magnitude(n->left) + 2 * magnitude(n->right);
}

node_t* copy(const node_t* n) {
  if (!n) return nullptr;
  auto* c = new node_t;
  c->value = n->value;
  c->left = copy(n->left);
  c->right = copy(n->right);
  if (c->left) c->left->parent = c;
  if (c->right) c->right->parent = c;
  return c;
}

int main() {
  vector<node_t*> numbers;
  string line;
  while (cin >> line) {
    int i = 0;
    numbers.push_back(parse_node(line, i));
  }
  int max_magnitude = 0;
  for (int i = 0; i < numbers.size(); i++) {
    for (int j = 0; j < numbers.size(); j++) {
      if (i == j) continue;
      auto* cp1 = copy(numbers[i]);
      auto* cp2 = copy(numbers[j]);
      auto* result = sum(cp1, cp2);
      reduce(result);
      int m = magnitude(result);
      max_magnitude = max(max_magnitude, m);
    }
  }
  cout << max_magnitude << endl;
  return 0;
}
