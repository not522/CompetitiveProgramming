#include "vector.hpp"
#include "string/join.hpp"
#include "string/split.hpp"

int main() {
  string s;
  getline(cin, s);
  auto v = split(s);
  int n;
  cin >> n;
  vector<string> t(n);
  cin >> t;
  for (auto& i : v) for (auto& j : t) if (i.size() == j.size() && inner_product(i.begin(), i.end(), j.begin(), true, logical_and<bool>(), [](char a, char b){return a == b || b == '*';})) i = string(i.size(), '*');
  cout << join(v) << endl;
}
