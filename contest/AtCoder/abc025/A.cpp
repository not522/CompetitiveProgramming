#include "string.hpp"

int main() {
  String s(in);
  int n(in);
  --n;
  cout << s[n / 5] << s[n % 5] << endl;
}
