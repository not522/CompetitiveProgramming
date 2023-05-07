#include "string.hpp"

int main() {
  String s(in);
  int res = -1;
  s.sort();
  do {
    ++res;
  } while (s.next_permutation());
  cout << res << endl;
}
