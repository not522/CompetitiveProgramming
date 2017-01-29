#include "math/basic.hpp"

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (ceil(a, b) * 2 >= ceil(a, c) * 3 ? "YES" : "NO") << endl;
}
