#include "template.hpp"

int main() {
  int d, n;
  cin >> d >> n;
  cout << (n + n / 100);
  for (int i = 0; i < d; ++i) cout << "00";
  cout << endl;
}
