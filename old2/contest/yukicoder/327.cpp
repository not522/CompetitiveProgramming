#include "string.hpp"

int main() {
  int64_t n(in);
  ++n;
  String s;
  do {
    --n;
    s = char('A' + n % 26) + s;
    n /= 26;
  } while (n);
  cout << s << endl;
}
