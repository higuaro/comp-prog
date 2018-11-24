#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
  string prev;
  do {
    ostringstream oss;
    int size = static_cast<int>(s.size());
    char current = 0;
    int count = 1;
    for (int i = 0; i < size + 1; i++) {
      char c = i < size ? s[i] : 0;
      if (c != current) {
        if ((count & 1) && current) oss << current;
        current = c;
        count = 1;
      } else 
        count++;
    }
    prev = s;
    s = oss.str();
  } while (s != prev);
  return s == "" ? "Empty String" : s;
}

int main()
{
    string s;
    getline(cin, s);

    string result = superReducedString(s);

    cout << result << "\n";

    return 0;
}

