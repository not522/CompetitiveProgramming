#include "template.hpp"

int main() {
  int n;
  cin >> n;
  string a = "indeednow";
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << (a == s ? "YES" : "NO") << endl;
  }
}
