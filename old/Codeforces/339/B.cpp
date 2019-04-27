#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  cin >> a;
  int p = 1;
  int64_t res = 0;
  for (int i : a) {
    res += p <= i ? i - p : n - p + i;
    p = i;
  }
  cout << res << endl;
}
