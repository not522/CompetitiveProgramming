#include "template.hpp"

int main() {
  set_bool_name("YES", "NO");
  int x;
  cin >> x;
  cout << (x == 3 || x == 5 || x == 7) << endl;
}
