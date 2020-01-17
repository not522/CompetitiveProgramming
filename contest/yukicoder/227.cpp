#include "vector.hpp"

int main() {
  Vector<int> c(13);
  for (int i = 0; i < 5; ++i) {
    ++c[int(in) - 1];
  }
  if (c.count(3) && c.count(2)) {
    cout << "FULL HOUSE" << endl;
  } else if (c.count(3)) {
    cout << "THREE CARD" << endl;
  } else if (c.count(2) == 2) {
    cout << "TWO PAIR" << endl;
  } else if (c.count(2)) {
    cout << "ONE PAIR" << endl;
  } else {
    cout << "NO HAND" << endl;
  }
}
