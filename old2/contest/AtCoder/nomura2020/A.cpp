#include "time.hpp"

int main() {
  int h1(in), m1(in), h2(in), m2(in), k(in);
  Time t1(h1, m1), t2(h2, m2);
  cout << (t2 - t1).toMinutes() - k << endl;
}
