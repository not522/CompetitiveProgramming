#include "template.hpp"

int main() {
  int w, d;
  cin >> w >> d;
  for (; d > 1; --d) w -= w / d / d;
  cout << w << endl;
}
