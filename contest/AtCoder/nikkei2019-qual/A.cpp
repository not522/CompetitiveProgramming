#include "template.hpp"

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(a, b) << " " << max(a + b - n, 0) << endl;
}
