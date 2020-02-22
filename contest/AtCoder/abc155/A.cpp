#include "vector.hpp"

int main() {
  Vector<int> v(3, in);
  v.sort();
  cout << (v[0] != v[2] && (v[0] == v[1] || v[1] == v[2])) << endl;
}
