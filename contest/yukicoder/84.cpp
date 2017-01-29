#include "template.hpp"

int main() {
  long long r, c;
  cin >> r >> c;
  cout << r * c / (r == c ? 4 : 2) - (r * c % 2 ? 0 : 1) << endl;
}
