#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  cin >> l;
  nth_element(l, n - k);
  cout << accumulate(subvector(l, n - k, n)) << endl;
}
