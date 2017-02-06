#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int a = -1, b = -1, res = numeric_limits<int>::max();
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
  cout << (res != numeric_limits<int>::max() ? res : -1) << endl;
}
