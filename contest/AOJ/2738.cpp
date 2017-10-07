#include "template.hpp"

int main() {
  int n, a = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "A") {
      ++a;
    } else {
      --a;
      if (a < 0) break;
    }
  }
  cout << (a == 0 ? "YES" : "NO") << endl;
}
