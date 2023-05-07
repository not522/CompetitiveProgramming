#include "geometry/ccw.hpp"

int main() {
  Segment segment(in);
  int q(in);
  for (int i = 0; i < q; ++i) {
    Point p(in);
    switch (ccw(segment, p)) {
    case LEFT:
      cout << "COUNTER_CLOCKWISE" << endl;
      break;
    case RIGHT:
      cout << "CLOCKWISE" << endl;
      break;
    case BACK:
      cout << "ONLINE_BACK" << endl;
      break;
    case FRONT:
      cout << "ONLINE_FRONT" << endl;
      break;
    case ON:
      cout << "ON_SEGMENT" << endl;
      break;
    }
  }
}
