#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; ++i) if (i % 3 == 0 || to_string(i).find('3') != string::npos) cout << i << endl;
}
