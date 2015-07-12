#include "template.hpp"

int main() {
  int n, res = numeric_limits<int>::max();
  cin >> n;
  for (int i = 0; i <= 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (i * 10 + j >= n) res = min(res, i * 100 + j * 15);
    }
  }
  cout << res << endl;
}
