#include "string.hpp"

int64_t toInteger(const String &s, int n) {
  int64_t res = 0;
  for (char c : s) {
    if (isdigit(c)) {
      res = res * n + c - '0';
    } else if (isalpha(c)) {
      res = res * n + tolower(c) - 'a' + 10;
    }
  }
  return res;
}

int main() {
  int n(in);
  int64_t res = toInteger("ZZZZZZZZZZZZ", 36);
  for (int i = 0; i < n; ++i) {
    String v(in);
    int mx = 0;
    for (char c : v) {
      if (isdigit(c)) {
        chmax(mx, c - '0' + 1);
      } else if (isalpha(c)) {
        chmax(mx, c - 'A' + 11);
      }
    }
    chmin(res, toInteger(v, mx));
  }
  cout << res << endl;
}
