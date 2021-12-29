#include <bits/stdc++.h>
using namespace std;

const int N = 100;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int n, m;
string s[N];

map<char, int> iat;
map<char, int> jat;

int nkeys;

vector<pair<char, int>> find(int i, int j, int keys) {
  vector<pair<char, int>> ans;
  queue<tuple<int, int, int>> q;
  vector<bool> was(n*m);
  q.emplace(i, j, 0);
  was[i*m + j] = true;
  while (!q.empty()) {
    int h;
    tie(i, j, h) = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int ii = i+di[k];
      int jj = j+dj[k];
      if (0 <= ii && ii < n &&
        0 <= jj && jj < m &&
        s[ii][jj] != '#' && !was[ii*m + jj])
      {
        char c = s[ii][jj];
        if ('a' <= c && c <= 'z' && !(keys & 1<<(c-'a'))) {
          ans.emplace_back(c, h+1);
        }
        if (c == '.' ||
          ('a' <= c && c <= 'z') ||
          ('A' <= c && c <= 'Z' && (keys & 1<<(c-'A'))))
        {
          q.emplace(ii, jj, h+1);
          was[ii*m + jj] = true;
        }
      }
    }
  }
  return ans;
}

int solve() {
  map<pair<char, int>, int> ans;
  set<tuple<int, char, int>> q;
  q.emplace(0, '@', 0);
  while (!q.empty()) {
    int len, c, keys;
    tie(len, c, keys) = *q.begin();
    q.erase(q.begin());

    if (keys == (1<<nkeys)-1) {
      return len;
    }

    for (auto& it : find(iat[c], jat[c], keys)) {
      char cc = it.first;
      int newlen = len + it.second;
      int newkeys = keys | 1<<(cc-'a');
      int curlen = ans[{cc, newkeys}];
      if (!curlen || curlen > newlen) {
        ans[{cc, newkeys}] = newlen;
        q.erase({curlen, cc, newkeys});
        q.emplace(newlen, cc, newkeys);
      }
    }
  }
  assert(false);
}

int main() {
  while (cin >> s[n]) {
    n += !s[n].empty();
  }
  m = s[0].size();

  map<char, pair<int, int>> pos;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] != '#' && s[i][j] != '.') {
        iat[s[i][j]] = i;
        jat[s[i][j]] = j;
        nkeys += 'a' <= s[i][j] && s[i][j] <= 'z';
      }
    }
  }

  int i = iat['@'];
  int j = jat['@'];
  s[i][j] = '.';

  cout << solve() << endl;
  return 0;
}

