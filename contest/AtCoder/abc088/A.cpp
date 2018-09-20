#include "template.hpp"

int main() {
  int n, a;
  cin >> n >> a;
  n %= 500;
  cout << (n <= a ? "Yes" : "No") << endl;
}
