#include "string.hpp"

int main() {
  int t(in);
  for (int i = 0; i < t; ++i) {
    String s(in);
    int res = inf<int>();
    for (int j = 0; j < int(s.size()) - 10; ++j) {
      int a = 0;
      for (int jj = 0; jj < 4; ++jj) {
        if (s[j + jj] != "good"[jj]) {
          ++a;
        }
      }
      for (int k = j + 4; k < int(s.size()) - 6; ++k) {
        int b = 0;
        for (int kk = 0; kk < 7; ++kk) {
          if (s[k + kk] != "problem"[kk]) {
            ++b;
          }
        }
        chmin(res, a + b);
      }
    }
    cout << res << endl;
  }
}
