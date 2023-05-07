#include "template.hpp"

int main() {
  int x(in), a(in), b(in);
  if (b <= a) {
    cout << "delicious" << endl;
  } else if (b <= a + x) {
    cout << "safe" << endl;
  } else {
    cout << "dangerous" << endl;
  }
}
