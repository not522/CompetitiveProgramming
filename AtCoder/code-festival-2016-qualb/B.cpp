#include "template.hpp"

int main() {
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  for (char c : s) {
    switch (c) {
    case 'a':
      if (a + b > 0) {
        cout << "Yes" << endl;
        --a;
      } else {
        cout << "No" << endl;
      }
      break;
    case 'b':
      if (a + b > 0 && b > 0) {
        cout << "Yes" << endl;
        --b;
      } else {
        cout << "No" << endl;
      }
      break;
    case 'c':
      cout << "No" << endl;
      break;
    }
  }
}
