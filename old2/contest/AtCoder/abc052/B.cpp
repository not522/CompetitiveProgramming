#include "string.hpp"

int main() {
  int n(in), x = 0, r = 0;
  (void)n;
  String s(in);
  for (char c : s) {
    if (c == 'I') {
      ++x;
    } else {
      --x;
    }
    chmax(r, x);
  }
  cout << r << endl;
}
