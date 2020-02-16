#include "template.hpp"

int main() {
  int m(in), d(in), res = 0;
  for (int i = 1; i <= d; ++i) {
    if (i % 10 >= 2 && i / 10 >= 2 && (i % 10) * (i / 10) <= m) {
      ++res;
    }
  }
  cout << res << endl;
}
