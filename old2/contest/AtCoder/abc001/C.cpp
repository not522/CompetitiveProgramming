#include "string.hpp"

int main() {
  int deg(in), dis(in);
  dis = (dis + 3) / 6;
  if (dis <= 2) {
    cout << "C 0" << endl;
    return 0;
  }
  Vector<int> ww({15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326});
  int w = ww.lower_bound(dis) + 1;
  String dir[] = {"N",   "NNE", "NE",  "ENE", "E",   "ESE", "SE",  "SSE", "S",
                  "SSW", "SW",  "WSW", "W",   "WNW", "NW",  "NNW", "N"};
  cout << dir[(deg * 10 + 1125) / 2250] << " " << w << endl;
}
