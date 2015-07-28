#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int res = -1;
  sort(s.begin(), s.end());
  do {
    ++res;
  } while (next_permutation(s.begin(), s.end()));
  cout << res << endl;
}
