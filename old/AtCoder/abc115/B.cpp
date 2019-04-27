#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  cout << accumulate(a) - max(a) / 2 << endl;
}
