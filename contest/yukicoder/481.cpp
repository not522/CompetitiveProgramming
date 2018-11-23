#include "vector.hpp"

int main() {
  vector<int> b(9);
  cin >> b;
  cout << 55 - accumulate(b) << endl;
}
