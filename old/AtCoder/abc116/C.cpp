#include "vector.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> h(n);
  cin >> h;
  while (any_of(h, [](int i){return i > 0;})) {
    if (h[0] > 0) ++res;
    for (int i = 1; i < n; ++i) {
      if (h[i - 1] <= 0 && h[i] > 0) ++res;
    }
    for (int& i : h) --i;
  }
  cout << res << endl;
}
