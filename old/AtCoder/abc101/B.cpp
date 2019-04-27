#include "template.hpp"

int main() {
  int n, s = 0;
  cin >> n;
  for (char c : to_string(n)) s += c - '0';
  cout << (n % s == 0 ? "Yes" : "No") << endl;
}
