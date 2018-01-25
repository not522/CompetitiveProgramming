#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  cout << (a * b % 2 ? "Odd" : "Even") << endl;
}
