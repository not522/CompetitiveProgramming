#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 2);
  for (int i = 0; i < n; ++i) cin  >> a[i + 1];
  int s = 0;
  for (int i = 0; i < n + 1; ++i) s += abs(a[i] - a[i + 1]);
  for (int i = 0; i < n; ++i) cout << s + abs(a[i] - a[i + 2]) - abs(a[i] - a[i + 1]) - abs(a[i + 1] - a[i + 2]) << endl;
}
