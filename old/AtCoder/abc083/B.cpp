#include "template.hpp"

int main() {
  int n, a, b, r = 0;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) {
    string s = to_string(i);
    int k = 0;
    for (char c : s) k += c - '0';
    if (a <= k && k <= b) r += i;
  }
  cout << r << endl;
}
