#include "string.hpp"
#include "time.hpp"

int main() {
  String t(in);
  int h = t.substr(0, 2), m = t.substr(3, 2);
  Time time(h, m, 0);
  time += Time(0, 5, 0);
  cout << std::setw(2) << std::setfill('0') << time.hour << ":" << std::setw(2)
       << std::setfill('0') << time.minute << endl;
}
