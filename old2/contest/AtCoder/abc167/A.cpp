#include "string.hpp"

int main() {
  String s(in), t(in);
  cout << (s == t.substr(0, t.size() - 1)) << endl;
}
