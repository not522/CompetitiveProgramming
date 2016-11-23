#include "template.hpp"

int main() {
  int64_t n;
  cin >> n;
  ++n;
  string s;
  do {
    --n;
    s = (char)('A' + n % 26) + s;
    n /= 26;
  } while (n);
  cout << s << endl;
}
