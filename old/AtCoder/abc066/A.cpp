#include "vector.hpp"

int main() {
  vector<int> v(3);
  cin >> v;
  sort(v);
  cout << v[0] + v[1] << endl;
}
