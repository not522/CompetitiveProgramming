#include "string/parser.hpp"

int main() {
  string s;
  cin >> s;
  long long res = numeric_limits<long long>::min();
  for (size_t i = 0; i < s.size(); ++i) {
    if (isdigit(s[0]) && isdigit(s.back())) res = max(res, parse(s));
    rotate(s.begin(), s.begin() + 1, s.end());
  }
  cout << res << endl;
}
