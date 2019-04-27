#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(3);
  cin >> a;
  rsort(a);
  for (int i = 0; ; ++i) {
    n -= a[i % 3];
    if (n <= 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
