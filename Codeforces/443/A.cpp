#include "string/replace_all.hpp"
#include "string/split.hpp"

int main() {
  string s;
  getline(cin, s);
  s = s.substr(1, s.size() - 2);
  replaceAll(s, " ", "");
  auto v = split(s, ',');
  cout << set<string>(v.begin(), v.end()).size() << endl;
}
