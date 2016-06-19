#include "vector.hpp"

int main() {
  int n, v;
  cin >> n;
  vector<int> a(n);
  cin >> a >> v;
  cout << accumulate(a) - v << endl;
}
