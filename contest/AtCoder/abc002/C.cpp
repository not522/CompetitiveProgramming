#include "geometry/segment.hpp"

int main() {
  Point a(in), b(in), c(in);
  cout << (Segment(b - a, c - a)).area().abs() << endl;
}
