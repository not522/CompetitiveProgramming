#include "string.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in);
  Vector<String> a(n, in);
  Map<String, int> m;
  for (auto s : a) {
    ++m[s];
    if (m[s] > (n + 1) / 2) {
      cout << false << endl;
      return 0;
    }
  }
  cout << true << endl;
}
