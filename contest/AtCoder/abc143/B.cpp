#include "math.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> d(n, in);
  cout << (square(d.accumulate()) - d.transform(square<int>).accumulate()) / 2
       << endl;
}
