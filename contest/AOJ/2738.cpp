#include "string.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in), a = 0;
  for (int i = 0; i < n; ++i) {
    if (String(in) == "A") {
      ++a;
    } else {
      --a;
      if (a < 0) {
        break;
      }
    }
  }
  cout << (a == 0) << endl;
}
