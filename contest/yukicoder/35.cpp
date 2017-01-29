#include "template.hpp"

int main() {
  int n, ok = 0, miss = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t;
    string s;
    cin >> t >> s;
    int k = min((int)s.size(), t * 12 / 1000);
    ok += k;
    miss += s.size() - k;
  }
  cout << ok << " " << miss << endl;
}
