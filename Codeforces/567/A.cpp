#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int64_t> x(n);
  cin >> x;
  for (int i = 0; i < n; ++i) {
    if (i == 0) cout << x[i + 1] - x[i];
    else if (i == n - 1) cout << x[i] - x[i - 1];
    else cout << min(x[i] - x[i - 1], x[i + 1] - x[i]);
    cout << " " << max(x[i] - x[0], x[n - 1] - x[i]) << endl;
  }
}
