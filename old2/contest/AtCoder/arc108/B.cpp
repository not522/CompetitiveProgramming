#include "string.hpp"

int main() {
  int n(in);
  String s(in);
  Vector<char> t;
  const Vector<char> fox{'f', 'o', 'x'};
  for (int i = 0; i < n; ++i) {
    t.emplace_back(s[i]);
    while (t.size() >= 3 && t.subvector(t.size() - 3) == fox) {
      for (int j = 0; j < 3; ++j) {
        t.pop_back();
      }
    }
  }
  cout << t.size() << endl;
}
