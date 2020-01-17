#include "math.hpp"
#include "vector.hpp"

int main() {
  int n(in), res = 0;
  Vector<int64_t> a(3, in);
  for (int i : a) {
    res += n / i;
  }
  for (int i = 0; i < 3; ++i) {
    res -= n / lcm(a[i], a[(i + 1) % 3]);
  }
  cout << res + n / lcm(a[0], a[1], a[2]) << endl;
}
