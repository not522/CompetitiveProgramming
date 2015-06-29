#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  sort(a.begin(), a.end(), greater<int>());
  unique(a.begin(), a.end());
  cout << a[1] << endl;
}
