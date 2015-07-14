#include "template.hpp"

int main() {
  int n;
  cin >> n;
  string res(n / 2, '1');
  if (n % 2) res[0] = '7';
  cout << res << endl;
}
