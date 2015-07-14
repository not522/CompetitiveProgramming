#include "day.hpp"

int main() {
  int res = 0;
  for (Day day(2015, 1, 1); day < Day(2016, 1, 1); ++day) {
    if (day.month == day.day / 10 + day.day % 10) ++res;
  }
  cout << res << endl;
}
