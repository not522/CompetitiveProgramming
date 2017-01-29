#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  cin >> v;
  auto m = minmax_element(v.begin(), v.end());
  cout << *m.second - *m.first << endl;
}
