#include "minmax.hpp"
#include "string/split.hpp"

int main() {
  int d;
  cin >> d;
  string s1, s2;
  cin >> s1 >> s2;
  string s = string(14, 'x') + s1 + s2 + string(14, 'x');
  auto v = split(s, 'x');
  auto res = max_element(v.begin(), v.end())->size();
  for (size_t i = 0; i < s.size(); ++i) {
    string ss = s;
    for (int j = 0; j < d && i + j < s.size() && s[i + j] == 'x'; ++j) {
      ss[i + j] = 'o';
      auto v = split(ss, 'x');
      chmax(res, max_element(v.begin(), v.end())->size());
    }
  }
  cout << res << endl;
}
