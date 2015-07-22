#include "template.hpp"

int solve(vector<int> a, vector<int> b) {
  while (!b.empty() && b.back() <= a.back()) b.pop_back();
  if (b.empty()) return 1;
  return solve(b, a) + 1;
}

int main() {
  int nw;
  cin >> nw;
  vector<int> w(nw);
  for (int& i : w) cin >> i;
  sort(w.rbegin(), w.rend());
  int nb;
  cin >> nb;
  vector<int> b(nb);
  for (int& i : b) cin >> i;
  sort(b.rbegin(), b.rend());
  cout << max(solve(w, b), solve(b, w)) << endl;
}
