#include "vector.hpp"

int main() {
  set_bool_name("YES", "NO");
  int64_t n, a;
  cin >> n >> a;
  vector<int64_t> x(n);
  cin >> x;
  cout << (n * a == accumulate(x)) << endl;
}
