#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  if (abs(a) < abs(b)) cout << "Ant" << endl;
  if (abs(a) > abs(b)) cout << "Bug" << endl;
  if (abs(a) == abs(b)) cout << "Draw" << endl;
}
