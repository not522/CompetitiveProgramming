#include "template.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  cout << (n <= 2 * k + 1 || n % 2 ? "first" : "second") << endl;
}
