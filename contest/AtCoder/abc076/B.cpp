#include "template.hpp"

int main() {
  int n, k, t = 1;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    if (t < k) t *= 2;
    else t += k;
  }
  cout << t << endl;
}
