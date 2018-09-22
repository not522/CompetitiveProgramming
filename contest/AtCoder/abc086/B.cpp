#include "string/to_integer.hpp"

int main() {
  string a, b;
  cin >> a >> b;
  int n = toInteger<int>(a + b);
  for (int i = 0; i * i <= n; ++i) {
    if (i * i == n) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
