#include "template.hpp"

int main() {
  int n, r, t = 0;
  string s;
  cin >> n >> r >> s;
  size_t last = s.find_last_of('.');
  if (last != string::npos) t += max(0, int(last) - r + 1);
  for (size_t p = 0; (p = s.find('.', p)) != string::npos; ++t, p += r) {
    for (int i = 0; i < r && p + i < s.size(); ++i) s[p + i] = 'o';
  }
  cout << t << endl;
}
