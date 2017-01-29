#include "template.hpp"

int main() {
  string a;
  cin >> a;
  string r = a;
  reverse(r.begin(), r.end());
  int c = 0;
  for (int i = 0; i < int(a.size()); ++i) {
    if (a[i] != r[i]) ++c;
  }
  if (c == 0) {
    cout << 25 * (a.size() - a.size() % 2) << endl;
  } else if (c == 2) {
    cout << 25 * a.size() - 2 << endl;
  } else {
    cout << 25 * a.size() << endl;
  }
}
