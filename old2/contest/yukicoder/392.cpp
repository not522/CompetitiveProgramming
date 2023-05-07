#include "string.hpp"

int main() {
  int m(in);
  for (int i = 0; i < m; ++i) {
    int a(in);
    String res;
    for (++a; a != 1; a /= 2) {
      res += a % 2 ? "R" : "L";
    }
    res.reverse();
    cout << res << endl;
  }
}
