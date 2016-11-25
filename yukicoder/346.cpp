#include "vector.hpp"

int main() {
  string s;
  cin >> s;
  vector<int64_t> c(s.size());
  reverse(s.begin(), s.end());
  for (uint i = 0; i < s.size(); ++i) c[i] = (s[i] == 'w' ? 1 : 0);
  partial_sum(c, c);
  reverse(s.begin(),s.end());
  reverse(c);
  int64_t res = 0;
  for (uint i = 0; i < s.size(); ++i) {
    if (s[i] == 'c') res += c[i] * (c[i] - 1) / 2;
  }
  cout << res << endl;
}
