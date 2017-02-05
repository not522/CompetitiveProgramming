#include "minmax.hpp"

int main() {
  int n, x = 0, r = 0;
  string s;
  cin >> n >> s;
  for (char c : s) {
    if (c == 'I') ++x;
    else --x;
    chmax(r, x);
  }
  cout << r << endl;
}
