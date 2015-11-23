#include "string/join.hpp"
#include "string/replace_all.hpp"
#include "string/split.hpp"

int main() {
  string s;
  cin >> s;
  replaceAll(s, "WUB", " ");
  auto t = split(s);
  t.erase(remove(t.begin(), t.end(), ""), t.end());
  cout << join(t) << endl;
}
