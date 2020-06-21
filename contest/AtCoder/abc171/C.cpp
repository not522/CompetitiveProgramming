#include "math/pow.hpp"
#include "string.hpp"

int main() {
  int64_t n(in);
  --n;
  for (int i = 1;; ++i) {
    int64_t c = pow(int64_t(26), i);
    if (n < c) {
      String res = "";
      for (int j = 0; j < i; ++j) {
        res += char('a' + n % 26);
        n /= 26;
      }
      cout << res.reverse() << endl;
      break;
    }
    n -= c;
  }
}
