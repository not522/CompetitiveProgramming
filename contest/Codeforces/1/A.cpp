#include "math/basic.hpp"

int main() {
  long long n, m, a;
  cin >> n >> m >> a;
  cout << ceil(n, a) * ceil(m, a) << endl;
}
