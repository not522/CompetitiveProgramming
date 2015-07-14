#include "string/split.hpp"

int main() {
  string c1, c2;
  cin >> c1 >> c2;
  auto v = split(c1 + c2, 'x');
  cout << max_element(v.begin(), v.end())->size() << endl;
}
