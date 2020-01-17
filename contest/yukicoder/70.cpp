#include "time.hpp"

int main() {
  int n(in), res = 0;
  for (int i = 0; i < n; ++i) {
    Time t1, t2;
    t1.hour = in;
    in.ignore();
    t1.minute = in;
    t2.hour = in;
    in.ignore();
    t2.minute = in;
    t2 -= t1;
    if (t2.toMinutes() < 0) {
      t2 += Time(24, 0, 0);
    }
    res += t2.toMinutes();
  }
  cout << res << endl;
}
