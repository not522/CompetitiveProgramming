#include "container/power_set.hpp"
#include "string.hpp"

int main() {
  String s(in);
  for (auto i : powerSet(3)) {
    int a = s[0] - '0';
    for (int j = 0; j < 3; ++j) {
      if (i.contains(j)) {
        a += s[j + 1] - '0';
      } else {
        a -= s[j + 1] - '0';
      }
    }
    if (a == 7) {
      for (int j = 0; j < 3; ++j) {
        cout << s[j] << (i.contains(j) ? '+' : '-');
      }
      cout << s[3] << "=7" << endl;
      return 0;
    }
  }
}
