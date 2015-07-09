#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) {
    cin >> i;
    i /= (i & -i);
  }
  sort(a.begin(), a.end());
  cout << unique(a.begin(), a.end()) - a.begin() << endl;
}
