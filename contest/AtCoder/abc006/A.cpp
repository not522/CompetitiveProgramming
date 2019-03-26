#include "template.hpp"

int main() {
  set_bool_name("YES", "NO");
  int n(in);
  if (n % 3 == 0) {
    cout << true << endl;
  } else {
    for (; n; n /= 3) {
      if (n % 10 == 3) {
        cout << true << endl;
        return 0;
      }
    }
    cout << false << endl;
  }
}
