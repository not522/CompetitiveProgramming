#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  cout << to_string(a).size() * to_string(b).size() << endl;
}
