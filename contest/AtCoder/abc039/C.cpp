#include "string.hpp"

int main() {
  const String res[] = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
  String s(in);
  s.resize(12);
  for (int i = 0;; ++i) {
    if (s == "WBWBWWBWBWBW") {
      cout << res[i] << endl;
      return 0;
    }
    rotate(s.rbegin(), find(s.rbegin(), s.rend(), 'W') + 1, s.rend());
  }
}
