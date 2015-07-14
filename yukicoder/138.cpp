#include "template.hpp"

int main() {
  array<int, 3> a, b;
  for (int& i : a) {
    cin >> i;
    cin.ignore();
  }
  for (int& i : b) {
    cin >> i;
    cin.ignore();
  }
  cout << (a >= b ? "YES" : "NO") << endl;
}
