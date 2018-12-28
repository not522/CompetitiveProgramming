#include "template.hpp"

int main() {
  string t;
  cin >> t;
  int res = 0, two = 0, five = 0;
  for (char c : t) {
    if (c == '2') {
      two = five + 1;
      five = 0;
    } else if (c == '5') {
      five = two ? two + 1 : 0;
      chmax(res, five);
      two = 0;
    } else if (c == '?') {
      int t = two;
      two = five + 1;
      five = t ? t + 1 : 0;
      chmax(res, five);
    } else {
      two = 0;
      five = 0;
    }
  }
  cout << res << endl;
}
