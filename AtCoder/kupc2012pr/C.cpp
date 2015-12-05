#include "template.hpp"

int main() {
  double y1, y2, y3;
  cout << "? 1" << endl;
  cin >> y1;
  cout << "? 2" << endl;
  cin >> y2;
  cout << "? 3" << endl;
  cin >> y3;
  double g = -y3 + 2 * y2 - y1;
  double v = (y2 - y1 + g * 1.5) * sqrt(2);
  double h = y1 + g / 2 - v / sqrt(2);
  cout << fixed << setprecision(15) << "! " << h << " " << v << " " << g << endl;
}
