#include "string.hpp"

int main() {
  String s(in);
  int res = 0;
  for (char c : s) {
    if (isdigit(c)) {
      res += c - '0';
    }
  }
  cout << res << endl;
}
