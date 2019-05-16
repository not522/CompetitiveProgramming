#include "string.hpp"

int main() {
  String s(in);
  auto f = [](const String &s) { return !s.split('*').contains("0"); };
  cout << s.split('+').count_if(f) << endl;
}
