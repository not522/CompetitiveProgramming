#include "string/find_all.hpp"

int main() {
  string s;
  cin >> s;
  auto v = find_all(s, "(^^*)");
  auto u = find_all(s, "(*^^)");
  cout << v.size() << " " << u.size() << endl;
}
