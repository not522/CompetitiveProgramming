#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int b = 0, w = 0;
  for (int i = 0; i < 8; ++i) {
    string k;
    cin >> k;
    b += count(k.begin(), k.end(), 'b');
    w += count(k.begin(), k.end(), 'w');
  }
  if ((b - w) % 2 == 0) cout << s << endl;
  else if (s == "oda") cout << "yukiko" << endl;
  else cout << "oda" << endl;
}
