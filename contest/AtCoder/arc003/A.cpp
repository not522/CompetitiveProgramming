#include "template.hpp"

int main() {
  int n, res = 0;
  string s;
  cin >> n >> s;
  for (char c : s) {
    if (c == 'F') continue;
    res += 'E' - c;
  }
  cout << double(res) / n << endl;
}
