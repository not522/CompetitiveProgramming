#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  for (const auto &i : a.countAll()) {
    cout << i.first << " " << i.second << endl;
  }
}
