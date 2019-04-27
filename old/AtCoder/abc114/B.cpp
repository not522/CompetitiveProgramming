#include "string/to_integer.hpp"

int main() {
  string s;
  cin >> s;
  int best = numeric_limits<int>::max();
  for (int i = 0; i + 3 <= int(s.size()); ++i) {
    int k = toInteger(s.substr(i, 3));
    if (abs(k - 753) < best) best = abs(k - 753);
  }
  cout << best << endl;
}
