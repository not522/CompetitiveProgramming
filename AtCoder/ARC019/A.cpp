#include "string/replace_all.hpp"

int main() {
  string s;
  cin >> s;
  replaceAll(s, "O", "0");
  replaceAll(s, "D", "0");
  replaceAll(s, "I", "1");
  replaceAll(s, "Z", "2");
  replaceAll(s, "S", "5");
  replaceAll(s, "B", "8");
  cout << s << endl;
}
