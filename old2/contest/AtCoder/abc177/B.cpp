#include "string.hpp"

int main() {
  String s(in), t(in);
  int res = t.size();
  for (int i = 0; i <= s.size() - t.size(); ++i) {
    int r = 0;
    for (int j = 0; j < t.size(); ++j) {
      if (s[i + j] != t[j]) {
        ++r;
      }
    }
    chmin(res, r);
  }
  cout << res << endl;
}
