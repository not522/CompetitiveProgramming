#include "template.hpp"

int main() {
  string n;
  cin >> n;
  sort(n.rbegin(), n.rend());
  cout << n << endl;
}
