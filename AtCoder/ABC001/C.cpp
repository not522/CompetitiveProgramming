#include "template.hpp"

int main() {
  int deg, dis;
  cin >> deg >> dis;
  dis = (dis + 3) / 6;
  if (dis <= 2) {
    cout << "C 0" << endl;
    return 0;
  }
  int w;
  if (dis <= 15) w = 1;
  else if (dis <= 33) w = 2;
  else if (dis <= 54) w = 3;
  else if (dis <= 79) w = 4;
  else if (dis <= 107) w = 5;
  else if (dis <= 138) w = 6;
  else if (dis <= 171) w = 7;
  else if (dis <= 207) w = 8;
  else if (dis <= 244) w = 9;
  else if (dis <= 284) w = 10;
  else if (dis <= 326) w = 11;
  else w = 12;
  string dir[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
  cout << dir[(deg * 10 + 1125) / 2250] << " " << w << endl;
}
