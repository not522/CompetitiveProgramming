#include "string.hpp"

int main() {
  String s(in);
  s = s.reverse().transform([](char c) { return c ^ '<' ^ '>'; });
  cout << s << endl;
}
