#include "template.hpp"

int main() {
  const string res[] = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
  string s;
  cin >> s;
  s.resize(12);
  for (int i = 0; ; ++i) {
    if (s == "WBWBWWBWBWBW") {
      cout << res[i] << endl;
      return 0;
    }
    rotate(s.rbegin(), find(s.rbegin(), s.rend(), 'W') + 1, s.rend());
  }
}
