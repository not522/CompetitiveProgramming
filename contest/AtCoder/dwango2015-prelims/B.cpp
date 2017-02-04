#include "string/replace_all.hpp"

int main() {
  string s;
  cin >> s;
  replaceAll(s, "25", ".");
  for (char& c : s) {
    if (isdigit(c)) c = ' ';
  }
  stringstream ss(s);
  int64_t res = 0;
  while (ss >> s) res += s.size() * (s.size() + 1) / 2;
  cout << res << endl;
}
