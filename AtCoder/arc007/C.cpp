#include "bit_operation.hpp"
#include "minmax.hpp"

int main() {
  string s;
  cin >> s;
  int n = s.size(), bit = 0, res = n;
  for (int i = 0; i < n; ++i) if (s[i] == 'o') bit |= 1 << i;
  for (int i = 0; i < (1 << n); ++i) {
    int m = 0;
    for (int j = 0; j < n; ++j) if (i & 1 << j) m |= (bit << j) % (1 << n) | bit >> (n - j);
    if (count_bit(m) == n) chmin(res, count_bit(i));
  }
  cout << res << endl;
}
