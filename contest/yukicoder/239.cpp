#include "string.hpp"
#include "vector.hpp"

int main() {
  const String nyanpass = "nyanpass";
  int n(in);
  Vector<Vector<String>> a(n, Vector<String>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[j][i] = in;
      if (a[j][i] == "-") {
        a[j][i] = nyanpass;
      }
    }
  }
  Vector<int> res;
  for (int i = 0; i < n; ++i) {
    if (a[i].count(nyanpass) == n) {
      res.emplace_back(i);
    }
  }
  cout << (res.size() == 1 ? res[0] + 1 : -1) << endl;
}
