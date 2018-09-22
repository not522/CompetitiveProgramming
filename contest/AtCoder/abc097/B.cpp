#include "template.hpp"

int main() {
  int x, r = 1;
  cin >> x;
  for (int i = 2; i <= x; ++i) {
    int k = i * i;
    for (int j = 2; k <= x; ++j, k *= i) r = max(r, k);
  }
  cout << r << endl;
}
