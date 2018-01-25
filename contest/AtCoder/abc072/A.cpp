#include "template.hpp"

int main() {
  int x, t;
  cin >> x >> t;
  cout << max(x - t, 0) << endl;
}
