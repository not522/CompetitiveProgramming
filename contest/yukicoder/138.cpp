#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  Vector<int> a(3), b(3);
  for (int &i : a) {
    i = in;
    in.ignore();
  }
  for (int &i : b) {
    i = in;
    in.ignore();
  }
  cout << (a >= b) << endl;
}
