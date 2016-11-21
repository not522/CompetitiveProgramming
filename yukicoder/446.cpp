#include "string/to_integer.hpp"

bool is_valid(string s) {
  for (char c : s) if (!isdigit(c)) return false;
  if (s.size() != 1u && s[0] == '0') return false;
  int n = toInteger<int>(s);
  return 0 <= n && n <= 12345;
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << (is_valid(a) && is_valid(b) ? "OK" : "NG") << endl;
}
