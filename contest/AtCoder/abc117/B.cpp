#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  cin >> l;
  cout << (2 * max(l) < accumulate(l)) << endl;
}
