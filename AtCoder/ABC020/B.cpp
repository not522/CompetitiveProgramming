#include "template.hpp"

int main() {
  string a, b;
  cin >> a >> b;
  stringstream ss(a + b);
  int n;
  ss >> n;
  cout << n * 2 << endl;
}
