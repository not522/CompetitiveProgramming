#include "template.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  auto m = minmax_element(v.begin(), v.end());
  cout << *m.second - *m.first << endl;
}
