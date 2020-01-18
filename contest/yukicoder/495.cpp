#include "string.hpp"

int main() {
  String s(in);
  auto v = s.find_all("(^^*)");
  auto u = s.find_all("(*^^)");
  cout << v.size() << " " << u.size() << endl;
}
