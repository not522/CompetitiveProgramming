#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  int sum = a.accumulate();
  if (sum % n) {
    cout << -1 << endl;
    return 0;
  }
  for (int &i : a) {
    i -= sum / n;
  }
  a = a.partial_sum();
  cout << n - a.count(0) << endl;
}
