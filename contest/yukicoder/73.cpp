#include "template.hpp"

int main() {
  long long c[26];
  for (auto& i : c) cin >> i;
  if (c['h' - 'a'] < 1 || c['e' - 'a'] < 1 || c['l' - 'a'] < 3 || c['o' - 'a'] < 2 || c['w' - 'a'] < 1 || c['r' - 'a'] < 1 || c['d' - 'a'] < 1) {
    cout << 0 << endl;
    return 0;
  }
  long long res = 1;
  res *= c['h' - 'a'];
  res *= c['e' - 'a'];
  long long r = 1;
  for (int i = 2; i <= c['l' - 'a'] - 1; ++i) r = max(r, i * (i - 1) / 2 * (c['l' - 'a'] - i));
  res *= r;
  r = 1;
  for (int i = 1; i <= c['o' - 'a'] - 1; ++i) r = max(r, i * (c['o' - 'a'] - i));
  res *= r;
  res *= c['w' - 'a'];
  res *= c['r' - 'a'];
  res *= c['d' - 'a'];
  cout << res << endl;
}
