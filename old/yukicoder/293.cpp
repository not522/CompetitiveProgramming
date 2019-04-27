#include "template.hpp"

int main() {
  string a, b;
  cin >> a >> b;
  if (a.size() != b.size()) {
    cout << (a.size() > b.size() ? a : b) << endl;
  } else {
    for (size_t i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        if ((a[i] == '4' || a[i] == '7') && (b[i] == '4' || b[i] == '7')) {
          cout << (a < b ? a : b) << endl;
        } else {
          cout << (a > b ? a : b) << endl;
        }
        break;
      }
    }
  }
}
