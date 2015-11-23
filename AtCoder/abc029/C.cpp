#include "template.hpp"

int n;

void solve(int i, string s) {
  if (i == n) {
    cout << s << endl;
    return;
  }
  for (char c = 'a'; c <= 'c'; ++c) solve(i + 1, s + c);
}

int main() {
  cin >> n;
  solve(0, "");
}
