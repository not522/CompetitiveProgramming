#include "time.hpp"

int main() {
  int n(in), h(in), m(in), t(in);
  Time time(h, m, 0);
  time += Time(0, (n - 1) * t, 0);
  cout << time.hour << endl << time.minute << endl;
}
