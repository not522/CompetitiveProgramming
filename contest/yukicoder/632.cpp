#include "vector.hpp"

int main() {
  vector<char> c(3);
  cin >> c;
  auto d = c, e = c;
  for (auto& i : d) {
    if (i == '?') i = '1';
  }
  for (auto& i : e) {
    if (i == '?') i = '4';
  }
  if (max(d) == d[1] || min(d) == d[1]) cout << 1;
  if (max(e) == e[1] || min(e) == e[1]) cout << 4;
  cout << endl;
}
