#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> v(n), f(n);
  cin >> v >> f;
  cout << inner_product(v.begin(), v.end(), f.begin(), 0, plus<int>(), [](int a, int b){return a / 2 < b;}) << endl;
}
