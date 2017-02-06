#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int& i : c) cin >> i;
  double res = 0;
  for (int i : c) {
    int cnt = 0;
    for (int j : c) {
      if (i % j == 0) ++cnt;
    }
    res += (cnt + 1) / 2. / cnt;
  }
  cout << res << endl;
}
