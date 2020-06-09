#include "template.hpp"

int main() {
  int n(in), r(in);
  if (n >= 10) {
    cout << r << endl;
  } else {
    cout << r + 100 * (10 - n) << endl;
  }
}
