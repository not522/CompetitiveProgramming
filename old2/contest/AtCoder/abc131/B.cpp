#include "template.hpp"

int main() {
  int n(in), l(in), s = n * l + n * (n - 1) / 2;
  if (l > 0) {
    cout << s - l << endl;
  } else if (l + n - 1 < 0) {
    cout << s - (l + n - 1) << endl;
  } else {
    cout << s << endl;
  }
}
