#include "template.hpp"

int main() {
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    string res;
    for (++a; a != 1; a /= 2) {
      res += a % 2 ? "R" : "L";
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
  }
}
