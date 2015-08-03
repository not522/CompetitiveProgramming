#include "template.hpp"

int main() {
  int n;
  cin >> n;
  cout << fixed << setprecision(15) << (10000 - n) / (100 + n * 0.98) << endl;
}
