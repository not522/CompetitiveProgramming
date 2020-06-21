#include "vector.hpp"

int main() {
  int n(in), k(in);
  Vector<int> p(n, in);
  cout << p.nth_element(k).partial_sum()[k - 1] << endl;
}
