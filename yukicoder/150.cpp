#include "template.hpp"

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    string s;
    cin >> s;
    int res = numeric_limits<int>::max();
    for (int j = 0; j < int(s.size()) - 10; ++j) {
      int a = 0;
      for (int jj = 0; jj < 4; ++jj) if (s[j + jj] != "good"[jj]) ++a;
      for (int k = j + 4; k < int(s.size()) - 6; ++k) {
        int b = 0;
        for (int kk = 0; kk < 7; ++kk) if (s[k + kk] != "problem"[kk]) ++b;
        res = min(res, a + b);
      }
    }
    cout << res << endl;
  }
}
