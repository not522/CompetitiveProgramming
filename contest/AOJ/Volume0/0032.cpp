#include "string/split.hpp"

int main() {
  string line;
  int res1 = 0, res2 = 0;
  while (cin >> line) {
    auto v = split(line, ',');
    int a = stoi(v[0]);
    int b = stoi(v[1]);
    int c = stoi(v[2]);
    if (a * a + b * b == c * c) ++res1;
    if (a == b) ++res2;
  }
  cout << res1 << endl << res2 << endl;
}
