#include "vector.hpp"

int main() {
  int n, x;
  cin >> n >> x;
  if (x == 1 || x == 2 * n - 1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  vector<int> v(2 * n - 1);
  iota(v, 1);
  swap(v[n - 1], v[x - 1]);
  swap(v[n - 2], v[0]);
  swap(v[n], v.back());
  cout << v;
}
