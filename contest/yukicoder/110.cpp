#include "vector.hpp"

int solve(vector<int> a, vector<int> b) {
  while (!b.empty() && b.back() <= a.back()) b.pop_back();
  if (b.empty()) return 1;
  return solve(b, a) + 1;
}

int main() {
  int nw;
  cin >> nw;
  vector<int> w(nw);
  cin >> w;
  rsort(w);
  int nb;
  cin >> nb;
  vector<int> b(nb);
  cin >> b;
  rsort(b);
  cout << max(solve(w, b), solve(b, w)) << endl;
}
