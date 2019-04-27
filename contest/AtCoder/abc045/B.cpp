#include "string.hpp"
#include "vector.hpp"

int main() {
  Vector<String> s(3, in);
  int t = 0;
  for (auto &i : s) {
    i.reverse();
  }
  while (true) {
    if (s[t].empty()) {
      cout << char(t + 'A') << endl;
      return 0;
    }
    int p = s[t].back() - 'a';
    s[t].pop_back();
    t = p;
  }
}
