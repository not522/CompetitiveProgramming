#include "vector.hpp"

int main() {
  int n, j = 0, res = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  unique(a);
  for (int i = 0; i < int(a.size()); ++i) {
    if (i == j || i - 1 == j) continue;
    if ((a[j] < a[j + 1]) != (a[i - 1] < a[i])) {
      ++res;
      j = i;
    }
  }
  cout << res + 1 << endl;
}
