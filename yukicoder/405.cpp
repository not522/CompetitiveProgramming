#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  vector<string> roman{"I", "II", "III", "IIII", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII"};
  string s1;
  int t;
  cin >> s1 >> t;
  cout << roman[mod(find(roman, s1) + t, 12)] << endl;
}
