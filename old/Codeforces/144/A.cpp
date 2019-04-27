#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  int i = max_element(a.begin(), a.end()) - a.begin();
  int j = min_element(a.rbegin(), a.rend()) - a.rbegin();
  cout << i + j - (i + j >= n ? 1 : 0) << endl;
}
