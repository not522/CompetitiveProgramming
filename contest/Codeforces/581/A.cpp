#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  cout << min(a, b) << " " << abs(a - b) / 2 << endl;
}
