#include "template.hpp"

int main() {
  int h, n, r = 1;
  cin >> h >> n;
  vector<int> v(n - 1);
  cin >> v;
  for (int i : v) {
    if (i > h) ++r;
  }
  cout << r;
  if (r % 10 == 1) cout << "st" << endl;
  else if (r % 10 == 2) cout << "nd" << endl;
  else if (r % 10 == 3) cout << "rd" << endl;
  else cout << "th" << endl;
}
