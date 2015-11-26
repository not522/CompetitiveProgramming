#include "template.hpp"

int main() {
  int k, res = 0;
  cin >> k;
  for (int i : {2, 3, 5, 7, 11 ,13}) for (int j : {4, 6, 8, 9, 10, 12}) if (i * j == k) ++res;
  cout << fixed << setprecision(15) << (double)res / 36 << endl;
}
