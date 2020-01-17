#include "string.hpp"

int main() {
  String s(in);
  int a = -1, b = -1, res = inf<int>();
  for (int i = 0; i < int(s.size()); ++i) {
    if (s[i] == 'c') {
      a = i;
    } else if (s[i] == 'w') {
      if (b != -1) {
        res = min(res, i - b + 1);
      }
      if (a != -1) {
        b = a;
      }
    }
  }
  cout << (res != inf<int>() ? res : -1) << endl;
}
