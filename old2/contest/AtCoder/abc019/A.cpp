#include "vector.hpp"

int main() {
  Vector<int> a(3, in);
  nth_element(a.begin(), a.begin() + 1, a.end());
  cout << a[1] << endl;
}
