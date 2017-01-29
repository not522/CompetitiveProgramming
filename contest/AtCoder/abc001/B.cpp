#include "template.hpp"

int main() {
  int m, vv;
  cin >> m;
  if (m < 100) vv = 0;
  else if (100 <= m && m <= 5000) vv = m / 100;
  else if (6000 <= m && m <= 30000) vv = m / 1000 + 50;
  else if (35000 <= m && m <= 70000) vv = (m / 1000 - 30) / 5 + 80;
  else if (70000 < m) vv = 89;
  else exit(-1);
  cout << setw(2) << setfill('0') << vv << endl;
}
