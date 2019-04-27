#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int& i : x) cin >> i;
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  adjacent_difference(x.begin(), x.end(), x.begin());
  cout << *min_element(x.begin() + 1, x.end()) << endl;
}
