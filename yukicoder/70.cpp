#include "time.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    Time t1, t2;
    cin >> t1.hour;
    cin.ignore();
    cin >> t1.minute >> t2.hour;
    cin.ignore();
    cin >> t2.minute;
    t2 -= t1;
    if (t2.toMinutes() < 0) t2 += Time(24, 0, 0);
    res += t2.toMinutes();
  }
  cout << res << endl;
}
