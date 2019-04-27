#include "math/basic.hpp"

int main() {
  int c;
  double rin, rout;
  cin >> c >> rin >> rout;
  cout << pow((rout - rin) / 2, 2) * pi() * (rout + rin) * pi() * c << endl;
}
