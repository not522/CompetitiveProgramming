#include "template.hpp"

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  if (int(s.size()) != a + b + 1 || s[a] != '-') {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < a + b + 1; ++i) {
    if (i != a && !isdigit(s[i])) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
