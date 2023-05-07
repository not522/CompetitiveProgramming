#include "string.hpp"

int main() {
  int n(in), k(in);
  (void)n;
  String s(in);
  s[k - 1] = std::tolower(s[k - 1]);
  cout << s << endl;
}
