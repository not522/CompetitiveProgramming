#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  cout << *min_element(v.begin(), v.end()) << endl;
}
