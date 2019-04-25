#include "string.hpp"

void solve(int i, int n, String s) {
  if (i == n) {
    cout << s << endl;
    return;
  }
  for (char c = 'a'; c <= 'c'; ++c) {
    solve(i + 1, n, s + c);
  }
}

int main() { solve(0, int(in), ""); }
