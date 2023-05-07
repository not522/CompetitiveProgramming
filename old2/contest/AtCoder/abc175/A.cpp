#include "string.hpp"

int main() {
  String s(in);
  int res = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j <= 3; ++j) {
      if (s.substr(i, j - i).count('S') == 0) {
        chmax(res, j - i);
      }
    }
  }
  cout << res << endl;
}
