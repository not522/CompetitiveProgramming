#include "template.hpp"

int main() {
  double r, d;
  cin >> r >> d;
  cout << fixed << setprecision(15) << r * r * M_PI * 2 * d * M_PI << endl;
}
