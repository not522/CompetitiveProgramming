#include "vector.hpp"

int main() {
  vector<int> a(3), b(3);
  cin >> a;
  for (int i = 0; i < 3; ++i) b[i] = abs(a[i] - a[(i + 1) % 3]);
  cout << accumulate(b) - max(b) << endl;
}
