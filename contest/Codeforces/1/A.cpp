#include "math/basic.hpp"

int main() {
  int64_t n, m, a;
  cin >> n >> m >> a;
  cout << ceil(n, a) * ceil(m, a) << endl;
}
