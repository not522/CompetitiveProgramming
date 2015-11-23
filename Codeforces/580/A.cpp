#include "template.hpp"

int main() {
  int n;
  cin >> n;
  int p = 0, c = 0, res = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    if (k < p) {
      res = max(res, c);
      c = 1;
    } else {
      ++c;
    }
    p = k;
  }
  cout << max(res, c) << endl;
}
