#include "vector.hpp"

int main() {
  int x(in), y(in);
  Vector<int> v(206);
  v[1] = 300000;
  v[2] = 200000;
  v[3] = 100000;
  if (x == 1 && y == 1) {
    cout << 1000000 << endl;
  } else {
    cout << v[x] + v[y] << endl;
  }
}
