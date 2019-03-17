#include "string.hpp"

int main() {
  set_bool_name("YES", "NO");
  int n, a = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    if (String(cin) == "A") {
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
