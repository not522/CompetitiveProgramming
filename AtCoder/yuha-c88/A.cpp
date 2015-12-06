#include "template.hpp"

int main() {
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; ++i) {
    string p, q, r;
    cin >> p >> q >> r;
    if (p == "BEGINNING") s += r[0];
    else if (p == "MIDDLE") s += r[r.size() / 2];
    else s += r.back();
  }
  cout << s << endl;
}
