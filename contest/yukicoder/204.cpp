#include "string.hpp"

int main() {
  int d(in);
  String s1(in), s2(in);
  String s = String(14, 'x') + s1 + s2 + String(14, 'x');
  auto v = s.split('x');
  if (v.empty()) {
    cout << d << endl;
    return 0;
  }
  auto res = v.max().size();
  for (int i = 0; i < s.size(); ++i) {
    String ss = s;
    for (int j = 0; j < d && i + j < s.size() && s[i + j] == 'x'; ++j) {
      ss[i + j] = 'o';
      auto v = ss.split('x');
      chmax(res, v.max().size());
    }
  }
  cout << res << endl;
}
