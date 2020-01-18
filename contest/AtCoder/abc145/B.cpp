#include "string.hpp"

int main() {
  int n(in);
  String s(in);
  if (n % 2) {
    cout << false << endl;
  } else {
    cout << (s == s.substr(n / 2) + s.substr(0, n / 2)) << endl;
  }
}
