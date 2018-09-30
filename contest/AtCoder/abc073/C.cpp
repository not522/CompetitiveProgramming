#include "template.hpp"

int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (!s.emplace(a).second) s.erase(a);
  }
  cout << s.size() << endl;
}
