#include "template.hpp"

int main() {
  int l, n;
  cin >> l >> n;
  vector<int> w(n);
  for (int& i : w) cin >> i;
  sort(w.begin(), w.end());
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += w[i];
    if (sum > l) {
      cout << i << endl;
      return 0;
    }
  }
  cout << n << endl;
}
