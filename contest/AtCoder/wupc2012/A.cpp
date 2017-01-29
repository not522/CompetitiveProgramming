#include "day.hpp"

int main() {
  Day a, b;
  a.year = b.year = 2012;
  cin >> a.month >> a.day;
  cin >> b.month >> b.day;
  cout << b - a << endl;
}
