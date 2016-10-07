#include "template.hpp"

int main() {
  int c;
  double rin, rout;
  cin >> c >> rin >> rout;
  cout << pow((rout - rin) / 2, 2) * M_PI * (rout + rin) * M_PI * c << endl;
}
