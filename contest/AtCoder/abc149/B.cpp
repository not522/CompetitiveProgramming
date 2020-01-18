#include "template.hpp"

int main() {
  int64_t a(in), b(in), k(in);
  if (a >= k) {
    cout << a - k << " " << b << endl;
  } else {
    cout << 0 << " " << max(b - k + a, int64_t(0)) << endl;
  }
}
