#include "template.hpp"

int main() {
  vector<int> a{0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  int x, y;
  cin >> x >> y;
  cout << (a[x] == a[y] ? "Yes" : "No") << endl;
}
