#include "string.hpp"

int main() {
  String a(in), b(in);
  if (a.size() != b.size()) {
    cout << (a.size() > b.size() ? a : b) << endl;
  } else {
    for (int i = 0; i < a.size(); ++i) {
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
