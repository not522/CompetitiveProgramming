#include "vector.hpp"

int main() {
  vector<int> a(3);
  cin >> a;
  sort(a);
  cout << accumulate(a) + 9 * a[2] << endl;
}
