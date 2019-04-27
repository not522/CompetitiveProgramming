#include "day.hpp"

int main() {
  vector<bool> h(366);
  for (Day d(2012, 1, 1); d.year == 2012; ++d) {
    int w = d.dayOfTheWeek();
    if (w == 0 || w == 6) h[d - Day(2012, 1, 1)] = true;
  }
  int n;
  cin >> n;
  vector<Day> day(n);
  for (auto& i : day) {
    i.year = 2012;
    cin >> i.month;
    cin.ignore();
    cin >> i.day;
    for (; i.year == 2012; ++i) {
      int d = i - Day(2012, 1, 1);
      if (!h[d]) {
        h[d] = true;
        break;
      }
    }
  }
  int r = 0, c = 0;
  for (auto i : h) {
    if (i) ++c;
    else c = 0;
    chmax(r, c);
  }
  cout << r << endl;
}
