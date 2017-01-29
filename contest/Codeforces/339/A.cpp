#include "string/join.hpp"
#include "string/split.hpp"

int main() {
  string s;
  cin >> s;
  auto v = split(s, '+');
  sort(v.begin(), v.end());
  cout << join(v, '+') << endl;
}
