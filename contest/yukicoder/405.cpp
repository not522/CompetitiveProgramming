#include "math.hpp"
#include "string.hpp"

int main() {
  Vector<String> roman{"I",   "II",   "III", "IIII", "V",  "VI",
                       "VII", "VIII", "IX",  "X",    "XI", "XII"};
  String s1(in);
  int t(in);
  cout << roman[mod(roman.find(s1) + t, 12)] << endl;
}
