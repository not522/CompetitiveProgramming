#include "template.hpp"

int main() {
  string x;
  cin >> x;
  int res = 0, s = 0;
  for (char c : x) {
    if (c == 'S') {
      ++s;
    } else if (s != 0) {
      ++res;
      --s;
    }
  }
  cout << x.size() - 2 * res << endl;
}
