#include "template.hpp"

int main() {
  int n;
  cin >> n;
  cout << "AB" << (n < 1000 ? 'C' : 'D') << endl;
}
