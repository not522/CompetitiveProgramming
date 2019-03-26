#include "map.hpp"
#include "string.hpp"

int main() {
  int n(in);
  Map<String, int> m;
  for (int i = 0; i < n; ++i) {
    ++m[String(in)];
  }
  cout << m.max([](auto a) { return a.second; }).first << endl;
}
