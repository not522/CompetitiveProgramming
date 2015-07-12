#include "day.hpp"

int main() {
  Day day;
  cin >> day.year;
  cin.ignore();
  cin >> day.month;
  cin.ignore();
  cin >> day.day;
  while (day.year % day.month != 0 || day.year / day.month % day.day != 0) day.next();
  cout << day.year << "/" << setw(2) << setfill('0') << day.month << "/" << setw(2) << setfill('0') << day.day << endl;
}
