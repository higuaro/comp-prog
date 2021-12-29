#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  const size_t K = 25 * 6;

  int zeroes = 0;
  int min_num_zeroes = numeric_limits<int>::max();
  int layer_with_min_0s = -1;
  int layer_index = 0;

  vector<array<char, K>> layers;
  array<char, K> current_layer;
  current_layer.fill(0);

  string d; cin >> d;
  for (size_t i = 0, k = 0; i < d.size(); i++) {
    if (i && !(i % K)) {
      if (zeroes < min_num_zeroes) {
        layer_with_min_0s = layer_index;
        min_num_zeroes = zeroes;
      }
      layer_index++;
      zeroes = 0;

      layers.push_back(current_layer);
      current_layer.fill(0);
    }
    current_layer[k] = d[i];
    if (d[i] == '0') zeroes++;

    k = (k + 1) % K;
  }
  if (zeroes < min_num_zeroes)
    layer_with_min_0s = layer_index;

  layers.push_back(current_layer);
  current_layer = layers[layer_with_min_0s];

  int num_1s = 0; int num_2s = 0;
  for (size_t k = 0; k < K; k++) {
    char c = current_layer[k];
    if (c == '1') num_1s++;
    if (c == '2') num_2s++;
  }
  cout << num_1s * num_2s << endl;

  return 0;
}
