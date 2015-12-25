#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> m(n);
  cin >> m;
  int a = accumulate(m) / n, r1 = 0, r2 = 0;
  for (int i : m) if (i < a) r1 += a - i;
  for (int i : m) if (i > a) r2 += i - a - 1;
  cout << max(r1, r2) << endl;
}
