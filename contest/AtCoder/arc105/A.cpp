#include "vector.hpp"

int main() {
  Vector<int> v(4, in);
  v.sort();
  cout << (2 * (v.min() + v.max()) == v.accumulate() ||
           2 * v.max() == v.accumulate())
       << endl;
}
