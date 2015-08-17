#include "template.hpp"

int main() {
  int n;
  cin >> n;
  cout << fixed << setprecision(15) << 4 * pow(0.75, n) << endl;
}
