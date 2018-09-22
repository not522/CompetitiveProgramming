#include "template.hpp"

int main() {
  int n, i = 0;
  cin >> n;
  for (; i * i <= n; ++i);
  cout << (i - 1) * (i - 1) << endl;
}
