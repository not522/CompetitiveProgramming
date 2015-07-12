#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (auto& s : v) {
    cin >> s;
    reverse(s.begin(), s.end());
  }
  sort(v.begin(), v.end());
  for (auto& s : v) {
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
}
