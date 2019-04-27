#include "string.hpp"
#include "vector.hpp"

int main() {
  int n(in), l(in);
  (void)l;
  Vector<String> s(n, in);
  s.sort();
  cout << s.accumulate() << endl;
}
