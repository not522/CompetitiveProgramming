#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; ; ++i) {
    if (accumulate(a.begin(), a.begin() + i, 0) > accumulate(a.begin() + i, a.end(), 0)) {
      cout << i << endl;
      return 0;
    }
  }
}
