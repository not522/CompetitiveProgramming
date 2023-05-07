#include "string.hpp"

int main() {
  int n(in);
  Vector<String> s(n, in), t(n, in);
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      cout << i + 1 << endl;
      cout << s[i] << endl;
      cout << t[i] << endl;
      return 0;
    }
  }
}
