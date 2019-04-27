#include "template.hpp"

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  --k;
  int d = (s[k] == '(' ? 1 : -1);
  int t = 0;
  while (true) {
    t += (s[k] == '(' ? 1 : -1);
    if (t == 0) break;
    k += d;
  }
  cout << k + 1 << endl;
}
