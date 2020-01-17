#include "vector.hpp"

int main() {
  setBoolName("win", "bust");
  cout << (Vector<int>(3, in).accumulate() <= 21) << endl;
}
