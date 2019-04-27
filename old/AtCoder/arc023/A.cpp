#include "day.hpp"

int main() {
  int y, m, d;
  cin >> y >> m >> d;
  Day day1(y, m, d), day2(2014, 5, 17);
  cout << day2 - day1 << endl;
}
