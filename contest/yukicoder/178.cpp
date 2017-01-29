#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<long long> c(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    c[i] = a + 4 * b;
  }
  if (any_of(c.begin(), c.end(), [&](long long i){return (c[0] - i) % 2;})) cout << -1 << endl;
  else cout << (*max_element(c.begin(), c.end()) * n - accumulate(c.begin(), c.end(), 0ll)) / 2 << endl;
}
