#include "string/replace_all.hpp"

int main() {
  string s;
  getline(cin, s);
  replaceAll(s, "Left", "<");
  replaceAll(s, "Right", ">");
  replaceAll(s, "AtCoder", "A");
  cout << s << endl;
}
