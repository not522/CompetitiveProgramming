#include "template.hpp"

int main() {
  string a, b;
  cin >> a >> b;
  cout << (a.size() > b.size() ? a : b) << endl;
}
