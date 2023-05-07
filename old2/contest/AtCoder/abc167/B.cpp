#include "template.hpp"

int main() {
  [[maybe_unused]] int a(in), b(in), c(in), k(in);
  if (k <= a) {
    cout << k << endl;
  } else if (k <= a + b) {
    cout << a << endl;
  } else {
    cout << a - (k - a - b) << endl;
  }
}
