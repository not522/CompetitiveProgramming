#include "template.hpp"

int main() {
  int n;
  cin >> n;
  array<pair<int, int>, 6> p;
  for (int i = 0; i < 6; ++i) p[i] = make_pair(0, i + 1);
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    ++p[l - 1].first;
  }
  cout << max_element(p.begin(), p.end())->second << endl;
}
