#include "template.hpp"

int main() {
  int n, r = numeric_limits<int>::max();
  cin >> n;
  for (int a = 1; a <= n / 2; ++a) {
    int b = n - a, k = 0;
    for (char c : to_string(a)) k += c - '0';
    for (char c : to_string(b)) k += c - '0';
    chmin(r, k);
  }
  cout << r << endl;
}
