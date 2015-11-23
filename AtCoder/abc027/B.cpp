#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  int sum = accumulate(a.begin(), a.end(), 0);
  if (sum % n) {
    cout << -1 << endl;
    return 0;
  }
  for (int& i : a) i -= sum / n;
  partial_sum(a.begin(), a.end(), a.begin());
  cout << n - count(a.begin(), a.end(), 0) << endl;
}
