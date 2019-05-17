#include "math.hpp"
#include "vector.hpp"

int main() {
  int64_t n(in);
  Vector<int64_t> v(5, in);
  cout << ceil(n, v.min()) + 4 << endl;
}
