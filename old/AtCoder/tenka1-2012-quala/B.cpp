#include "string/replace_all.hpp"

int main() {
  string s;
  getline(cin, s);
  replaceAll<true>(s, "  ", " ");
  replaceAll(s, " ", ",");
  cout << s << endl;
}
