#include "template.hpp"

int main() {
  array<int, 3> n, p;
  for (int& i : n) cin >> i;
  for (int& i : p) cin >> i;
  sort(p.begin(), p.end());
  int res = 0;
  do {
    res = max(res, (n[0] / p[0]) * (n[1] / p[1]) * (n[2] / p[2]));
  } while (next_permutation(p.begin(), p.end()));
  cout << res << endl;
}
