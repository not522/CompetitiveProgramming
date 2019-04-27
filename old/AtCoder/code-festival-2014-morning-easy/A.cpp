#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  adjacent_difference(a, a);
  cout << double(accumulate(a) - a[0]) / (n - 1) << endl;
}
