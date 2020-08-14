#include "vector.hpp"

int main() {
  int n(in), m(in);
  Vector<int> a(m, in);
  int sum = a.accumulate();
  if (n >= sum) {
    cout << n - sum << endl;
  } else {
    cout << -1 << endl;
  }
}
