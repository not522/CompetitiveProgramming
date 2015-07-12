#include "template.hpp"

int main() {
  string day;
  cin >> day;
  if (day == "Sunday") cout << 0 << endl;
  if (day == "Monday") cout << 5 << endl;
  if (day == "Tuesday") cout << 4 << endl;
  if (day == "Wednesday") cout << 3 << endl;
  if (day == "Thursday") cout << 2 << endl;
  if (day == "Friday") cout << 1 << endl;
  if (day == "Saturday") cout << 0 << endl;
}
