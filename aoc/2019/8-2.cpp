#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string d; cin >> d;

  const size_t W = 25;
  const size_t H = 6;
  const size_t K = W * H;

  vector<array<char, K>> layers;
  array<char, K> current_layer;
  current_layer.fill(0);

  for (size_t i = 0, k = 0; i < d.size(); i++) {
    if (i && !(i % K)) {
      layers.push_back(current_layer);
      current_layer.fill(0);
    }
    current_layer[k] = d[i];
    k = (k + 1) % K;
  }
  layers.push_back(current_layer);

  array<char, K> image; image.fill(0);
  for (size_t r = 0; r < H; r++) {
    for (size_t c = 0; c < W; c++) {
      size_t offset = W * r + c;
      for (auto layer : layers) {
        if (layer[offset] != '2') {
          image[offset] = layer[offset];
          break;
        }
      }
    }
  }

  for (size_t r = 0; r < H; r++) {
    for (size_t c = 0; c < W; c++) {
      char digit = image[W * r + c];
      cout << (digit == '0' ? ' ' : digit);
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
