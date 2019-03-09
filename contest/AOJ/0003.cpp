#include "vector.hpp"

int main() {
  set_bool_name("YES", "NO");
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    Vector<int> a(3, cin);
    a.sort();
    cout << (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) << endl;
  }
}
