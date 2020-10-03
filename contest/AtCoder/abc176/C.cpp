#include "vector.hpp"

int main() {
  int n(in), k = 0;
  Vector<int> a(n, in);
  int64_t res = 0;
  for (int b : a) {
    if (b > k) {
      k = b;
    } else {
      res += k - b;
    }
  }
  cout << res << endl;
}
