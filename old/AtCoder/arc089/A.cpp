#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> t(n + 1), x(n + 1), y(n + 1);
  for (int i = 0; i < n; ++i) cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
  for (int i = 0; i < n; ++i) {
    int d = abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
    if (d > t[i + 1] - t[i] || d % 2 != (t[i + 1] - t[i]) % 2) {
      cout << false << endl;
      return 0;
    }
  }
  cout << true << endl;
}
