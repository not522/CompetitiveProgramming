#include "day.hpp"
#include "string.hpp"

int main() {
  for (int m, d; cin >> m >> d, m != 0 || d != 0;) {
    Day day(2004, m, d);
    String week[]{"Sunday",   "Monday", "Tuesday", "Wednesday",
                  "Thursday", "Friday", "Saturday"};
    cout << week[day.dayOfTheWeek()] << endl;
  }
}
