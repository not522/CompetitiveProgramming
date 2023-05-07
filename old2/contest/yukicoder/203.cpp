#include "string.hpp"

int main() {
  String c1(in), c2(in);
  auto v = (c1 + c2).split('x');
  if (v.empty()) {
    cout << 0 << endl;
  } else {
    cout << v.max().size() << endl;
  }
}
