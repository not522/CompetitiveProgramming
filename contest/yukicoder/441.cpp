#include "string.hpp"

int main() {
  String a(in), b(in);
  int x = (a.size() > 1 ? 10 : int(a));
  int y = (b.size() > 1 ? 10 : int(b));
  if (x + y > x * y) {
    cout << "S" << endl;
  }
  if (x + y < x * y) {
    cout << "P" << endl;
  }
  if (x + y == x * y) {
    cout << "E" << endl;
  }
}
