#include "template.hpp"

int main() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += min((a[i] - b[i] + 10) % 10, (b[i] - a[i] + 10) % 10);
  }
  cout << res << endl;
}
