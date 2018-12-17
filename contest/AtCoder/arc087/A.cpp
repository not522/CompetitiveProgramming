#include "vector.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  auto m = count_kinds(a);
  for (auto i : m) {
    if (i.first > i.second) res += i.second;
    else res += i.second - i.first;
  }
  cout << res << endl;
}
