#include "set.hpp"

int main() {
  int n(in);
  Set<int> s;
  for (int i = 0; i < n; ++i) {
    int a(in);
    if (!s.emplace(a).second) {
      s.erase(a);
    }
  }
  cout << s.size() << endl;
}
