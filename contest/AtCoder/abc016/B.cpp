#include "template.hpp"

int main() {
  int a(in), b(in), c(in);
  if (a + b == c && a - b == c) {
    cout << "?" << endl;
  }
  if (a + b == c && a - b != c) {
    cout << "+" << endl;
  }
  if (a + b != c && a - b == c) {
    cout << "-" << endl;
  }
  if (a + b != c && a - b != c) {
    cout << "!" << endl;
  }
}
