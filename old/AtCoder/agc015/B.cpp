#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int64_t n = s.size();
  int64_t res = n * (n - 1);
  for (int i = 0; i < n; ++i) res += (s[i] == 'U' ? i : n - i - 1);
  cout << res << endl;
}
