#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v[i] = y - x;
  }
  cout << (count(v.begin(), v.end(), v[0]) == int(v.size()) && v[0] > 0 ? v[0] : -1) << endl;
}
