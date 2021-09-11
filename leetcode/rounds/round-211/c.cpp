#include <bits/stdc++.h>

using namespace std;

string d(bitset<1000> b, int n) {
  auto s = b.to_string();
  reverse(begin(s), end(s));
  return s.substr(0, n);
}
class Solution {
public:
  static const int N = 1000;
  int solve(const vector<int>& scores, const vector<int>& ages,
            int i, bitset<N> team) {
    if (i == scores.size()) {
      int team_score = 0;
      for (int k = 0; k < i; k++)
        if (team.test(k)) team_score += scores[k];
      cout << team_score << " team: " << team.to_string() << endl;
      return team_score;
    }

    int a = ages[i];
    int s = scores[i];
    int max_score = 0;
    for (int k = 0; k < i; k++) {
      if (team.test(k)) {
        int pa = ages[k];
        int ps = scores[k];
        if (a < pa && s > ps)
          return -1;
        max_score += ps;
      }
    }
    int max1 = max(max_score, solve(scores, ages, i + 1, team));
    team.set(i);
    max_score += s;
    int max2 = max(max_score, solve(scores, ages, i + 1, team));
    return max(max1, max2);
  }
  int bestTeamScore(const vector<int>& scores, const vector<int>& ages) {
    bitset<N> s;
    return solve(scores, ages, 0, s);
  }
};

int main() {
  vector<int> scores{9,2,8,8,2};
  vector<int> ages{4,1,3,3,5};
  cout << Solution().bestTeamScore(scores, ages) << endl;
  return 0;
}
