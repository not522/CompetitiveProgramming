#include "string.hpp"

int main() {
  String s(in);
  Map<char, int> m;
  for (char c : s) {
    ++m[c];
  }
  cout << min({m['t'], m['r'], m['e'] / 2}) << endl;
}
