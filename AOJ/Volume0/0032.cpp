#include "string/split.hpp"
#include "string/to_integer.hpp"

int main() {
  string line;
  int res1 = 0, res2 = 0;
  while (cin >> line) {
    auto v = split(line, ',');
    int a = toInteger<int>(v[0]);
    int b = toInteger<int>(v[1]);
    int c = toInteger<int>(v[2]);
    if (a * a + b * b == c * c) ++res1;
    if (a == b) ++res2;
  }
  cout << res1 << endl << res2 << endl;
}
