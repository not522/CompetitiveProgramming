#include "vector.hpp"

int main() {
  int n, x, r = 0;
  cin >> n >> x;
  vector<int> a(n);
  cin >> a;
  sort(a);
  for (int i : a) {
    if (i <= x) {
      x -= i;
      ++r;
    }
  }
  if (r == n && x > 0) --r;
  cout << r << endl;
}
