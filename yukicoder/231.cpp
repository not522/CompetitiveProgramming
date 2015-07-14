#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    int g, d;
    cin >> g >> d;
    v[i] = g - 30000 * d;
  }
  if (3000000 <= *max_element(v.begin(), v.end()) * 6) {
    cout << "YES" << endl;
    for (int i = 0; i < 6; ++i) cout << max_element(v.begin(), v.end()) - v.begin() + 1 << endl;
  } else {
    cout << "NO" << endl;
  }
}
