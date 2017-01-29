#include "day.hpp"

bool solve() {
  int m, d;
  cin >> m >> d;
  if (m == 0 && d == 0) return false;
  Day day(2004, m, d);
  string week[]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  cout << week[day.dayOfTheWeek()] << endl;
  return true;
}

int main() {
  while (solve());
}
