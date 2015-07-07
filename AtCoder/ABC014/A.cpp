#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  cout << (a % b ? b - a % b : 0) << endl;
}
