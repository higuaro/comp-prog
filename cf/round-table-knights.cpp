#include <bits/stdc++.h>
int main() {
  using namespace std;

  array<bool, static_cast<int>(1e5 + 1)> knights{false};
  int N; cin >> N;
  int total_good_mood = 0;
  for (int i = 0; i < N; i++) {
    int mood; cin >> mood;
    knights[i] = mood;
    total_good_mood += mood;
  }

  for (int jump = 1; jump <= N / 3; jump++) {
    if ((N % jump) || (N / jump) > total_good_mood) continue;
    for (int start = 0; start < jump; start++) {
      int pos = start;
      while (pos < N) {
        if (!knights[pos]) break;
        pos += jump;
      }
      if (pos >= N) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;

  return 0;
}
