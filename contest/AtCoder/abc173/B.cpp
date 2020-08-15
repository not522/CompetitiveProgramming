#include "string.hpp"

int main() {
  int n(in), ac = 0, wa = 0, tle = 0, re = 0;
  for (int i = 0; i < n; ++i) {
    String s(in);
    if (s == "AC") {
      ++ac;
    } else if (s == "WA") {
      ++wa;
    } else if (s == "TLE") {
      ++tle;
    } else {
      ++re;
    }
  }
  cout << "AC x " << ac << endl;
  cout << "WA x " << wa << endl;
  cout << "TLE x " << tle << endl;
  cout << "RE x " << re << endl;
}
