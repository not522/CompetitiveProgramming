#include "template.hpp"

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  complex<double> p1(x1, y1), p2(x2, y2);
  auto p3 = p2 + (p2 - p1) * complex<double>(0, 1);
  auto p4 = p3 + (p3 - p2) * complex<double>(0, 1);
  cout << int(p3.real()) << " " << int(p3.imag()) << " " << int(p4.real()) << " " << int(p4.imag()) << endl;
}
