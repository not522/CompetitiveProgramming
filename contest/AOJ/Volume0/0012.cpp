#include "geometry/polygon.hpp"

int main() {
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    Polygon pol(3);
    Point p;
    for (auto& i : pol) ss >> i;
    ss >> p;
    cout << (pol.cover(p) ? "YES" : "NO") << endl;
  }
}
