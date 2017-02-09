#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  int mx = max(a);
  multiset<int> m(a.begin(), a.end());
  for (int i = mx / 2 + 1; i <= mx; ++i) {
    for (int k = 0; k < 2; ++k) {
      auto itr = m.find(i);
      if (itr == m.end()) {
        cout << "Impossible" << endl;
        return 0;
      }
      m.erase(itr);
    }
  }
  if (mx % 2 == 0) {
    auto itr = m.find(mx / 2);
    if (itr == m.end()) {
      cout << "Impossible" << endl;
      return 0;
    }
    m.erase(itr);
  }
  if (!m.empty() && *m.begin() <= (mx + 1) / 2) {
    cout << "Impossible" << endl;
  } else {
    cout << "Possible" << endl;
  }
}
