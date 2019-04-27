#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int& i : s) cin >> i;
  sort(s.rbegin(), s.rend());
  for (int& i : s) {
    if (i != 0) ++i;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int k;
    cin >> k;
    cout << s[k] << endl;
  }
}
