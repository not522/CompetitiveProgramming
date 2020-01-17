#include "string/find_all.hpp"

int main() {
  String s(in);
  auto v = find_all(s, "(^^*)");
  auto u = find_all(s, "(*^^)");
  cout << v.size() << " " << u.size() << endl;
}
