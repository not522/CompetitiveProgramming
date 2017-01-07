#include "string/replace_all.hpp"

int main() {
  string s;
  cin >> s;
  replaceAll(s, ",", " ");
  cout << s << endl;
}
