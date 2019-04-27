#include "template.hpp"

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if (b <= a) cout << "delicious" << endl;
  else if (b <= a + x) cout << "safe" << endl;
  else cout << "dangerous" << endl;
}
