#include "template.hpp"

int main() {
  set_bool_name("YES", "NO");
  int t(in);
  for (int i = 0; i < t; ++i) {
    int a = 0, b = 0;
    bool f = true;
    for (int i = 0; i < 10; ++i) {
      int c(in);
      if (c < a) {
        f = false;
      } else if (c < b) {
        a = c;
      } else {
        b = c;
      }
    }
    cout << f << endl;
  }
}
