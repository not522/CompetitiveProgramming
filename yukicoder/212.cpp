#include "template.hpp"

int main() {
  int p, c;
  cin >> p >> c;
  cout << fixed << setprecision(15) << pow((2 + 3 + 5 + 7 + 11 + 13) / 6.0, p) * pow((4 + 6 + 8 + 9 + 10 + 12) / 6.0, c) << endl;
}
