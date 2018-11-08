#include "template.hpp"

int main() {
  string n;
  cin >> n;
  for (char c : n) cout << char(c ^ '1' ^ '9');
  cout << endl;
}
