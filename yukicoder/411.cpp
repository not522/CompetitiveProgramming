#include "template.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  cout << (1 << (n - k)) - (k == 1 ? n : 0) << endl;
}
