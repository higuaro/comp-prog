#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> reaction;

map<string, pair<int, vector<reaction>>> formulas;
map<string, int64_t> surplus;

reaction parse_reaction(string& line) {
  istringstream ss(line);
  int quantity; ss >> quantity;
  string element; ss >> element;
  return make_pair(element, quantity);
}

vector<reaction> parse_components(string& line) {
  vector<reaction> components;
  istringstream ss(line);
  int quantity;
  string element;
  while (ss >> quantity) {
    ss.ignore(1);
    getline(ss, element, ',');
    components.push_back(make_pair(element, quantity));
  }
  return components;
}

int64_t produce(int64_t quantity, const string& element) {
  if (element == "ORE") return quantity;
  if (surplus[element] >= quantity) {
    surplus[element] -= quantity;
    return 0L;
  }
  quantity -= surplus[element];
  int64_t ores = 0;

  auto formula = formulas[element];
  int64_t to_produce = formula.first;
  auto components = formula.second;

  int64_t repeats = quantity >= to_produce
    ? quantity / to_produce + (quantity % to_produce ? 1 : 0)
    : 1;
  for (auto comp : components) {
    ores += produce(repeats * comp.second, comp.first);
  }
  surplus[element] = repeats * to_produce - quantity;

  return ores;
}

int main() {
  string line;
  while (getline(cin, line, '\n')) {
    string delimiter = " => ";
    auto split_pos = line.find(delimiter);
    string components = line.substr(0, split_pos);
    string product = line.substr(split_pos + delimiter.size(), line.size());

    auto p = parse_reaction(product);
    auto c = parse_components(components);

    auto formula = make_pair(p.second, c);
    string element = p.first;
    formulas[element] = formula;
    surplus[element] = 0;
  }

  cout << produce(1, "FUEL") << endl;

  return 0;
}
