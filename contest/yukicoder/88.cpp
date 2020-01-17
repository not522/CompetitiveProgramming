#include "string.hpp"

int main() {
  String s(in);
  int b = 0, w = 0;
  for (int i = 0; i < 8; ++i) {
    String k(in);
    b += count(k.begin(), k.end(), 'b');
    w += count(k.begin(), k.end(), 'w');
  }
  if ((b - w) % 2 == 0) {
    cout << s << endl;
  } else if (s == "oda") {
    cout << "yukiko" << endl;
  } else {
    cout << "oda" << endl;
  }
}
