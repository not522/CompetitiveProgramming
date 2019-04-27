#include "time.hpp"
#include "string/to_integer.hpp"

int main() {
  string t;
  cin >> t;
  int h = toInteger(t.substr(0, 2));
  int m = toInteger(t.substr(3, 2));
  Time time(h, m, 0);
  time += Time(0, 5, 0);
  cout << setw(2) << setfill('0') << time.hour << ":" << setw(2) << setfill('0') << time.minute << endl;
}
