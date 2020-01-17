#include "string.hpp"

int main() {
  String s(in);
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 1; i + j <= s.size() && j < s.size(); ++j) {
      String ss = s.substr(i, j), r = ss;
      r.reverse();
      if (ss == r) {
        chmax(res, j);
      }
    }
  }
  cout << res << endl;
}
