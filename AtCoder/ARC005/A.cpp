#include "template.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string w;
    cin >> w;
    if (w.back() == '.') w.pop_back();
    if (w == "TAKAHASHIKUN") ++res;
    if (w == "Takahashikun") ++res;
    if (w == "takahashikun") ++res;
  }
  cout << res << endl;
}
