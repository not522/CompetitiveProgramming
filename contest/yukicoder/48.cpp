#include "math.hpp"

int main() {
  int x(in), y(in), l(in);
  cout << (y < 0 ? 2 : x != 0 ? 1 : 0) + ceil(abs(x), l) + ceil(abs(y), l)
       << endl;
}
