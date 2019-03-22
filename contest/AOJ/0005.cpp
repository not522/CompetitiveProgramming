#include "math/basic.hpp"

int main() {
  for (int a, b; a = in, b = in, !in.eof;) {
    cout << gcd(a, b) << " " << lcm(a, b) << endl;
  }
}
