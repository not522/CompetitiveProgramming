#include "vector.hpp"

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  cin >> a;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] + a[i + 1] >= l) {
      cout << "Possible" << endl;
      for (int j = 0; j < i; ++j) {
        cout << j + 1 << endl;
      }
      for (int j = n - 1; j > i; --j) {
        cout << j << endl;
      }
      return 0;
    }
  }
  cout << "Impossible" << endl;
}
