#include "template.hpp"

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  n %= a + b;
  cout << (0 < n && n <= a ? "Ant" : "Bug") << endl;
}
