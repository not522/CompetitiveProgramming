#include "day.hpp"

int solve(long long n) {
  Day day(0, 7, 23);
  int res = 0;
  for (int i = 0; i < 400; ++i) {
    day.year = i;
    if (day.weekday() == Day::WED) ++res;
  }
  res *= n / 400;
  for (int i = 0; i <= n % 400; ++i) {
    day.year = i;
    if (day.weekday() == Day::WED) ++res;
  }
  return res;
}

int main() {
  long long n;
  cin >> n;
  cout << solve(n) - solve(2014) << endl;
}
