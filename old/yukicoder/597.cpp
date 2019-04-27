#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  for (auto i : s) cout << i;
  cout << endl;
}
