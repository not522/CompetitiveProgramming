#include "template.hpp"

int main() {
  int n;
  cin >> n;
  if (n % 3 == 0) {
    cout << "YES" << endl;
  } else {
    for (; n; n /= 3) {
      if (n % 10 == 3) {
        cout << "YES" << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
  }
}
