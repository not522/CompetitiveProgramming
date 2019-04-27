#include "time.hpp"

int main() {
  Time a(18, 0, 0), b;
  cin >> b.hour >> b.minute;
  cout << (a - b).toMinutes() << endl;
}
