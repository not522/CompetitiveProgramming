#include "template.hpp"

int main() {
  int n, r = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] == a[i]) {
      a[i] = -1;
      ++r;
    }
  }
  cout << r << endl;
}
