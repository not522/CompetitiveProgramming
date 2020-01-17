#include "template.hpp"

int main() {
  int t(in), a(in), b(in);
  if ((a == 0 && b == 0 && t == 1) || max(a, b) > t) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  if ((max(a, b) - t) % 2) {
    if (a && b) {
      cout << "^" << endl;
      cout << ">" << endl;
      --a, --b, t -= 2;
    } else if (a) {
      cout << "^>" << endl;
      cout << "<" << endl;
      --a, t -= 2;
    } else if (b) {
      cout << "^>" << endl;
      cout << "v" << endl;
      --b, t -= 2;
    } else {
      cout << "v<" << endl;
      cout << ">" << endl;
      cout << "^" << endl;
      t -= 3;
    }
  }
  for (int i = 0; i < t; ++i) {
    if (a && b) {
      cout << "^>" << endl;
      --a, --b;
    } else if (a) {
      cout << "^" << endl;
      --a;
    } else if (b) {
      cout << ">" << endl;
      --b;
    } else {
      cout << "v<" << endl;
      ++a, ++b;
    }
  }
}
