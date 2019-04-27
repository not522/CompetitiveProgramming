#include "vector.hpp"

int main() {
  int p1, p2, n, t = 0;
  cin >> p1 >> p2 >> n;
  vector<int> r(n);
  cin >> r;
  auto m = count_kinds(r);
  for (auto i : m) t += i.second - 1;
  cout << (p1 + p2) * t << endl;
}
