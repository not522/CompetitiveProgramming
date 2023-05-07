#include "string.hpp"

bool is_valid(String s) {
  if (!s.all_of(isdigit) || (s.size() != 1 && s[0] == '0')) {
    return false;
  }
  int n = s;
  return 0 <= n && n <= 12345;
}

int main() {
  setBoolName("OK", "NG");
  String a(in), b(in);
  cout << (is_valid(a) && is_valid(b)) << endl;
}
