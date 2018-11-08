#include "vector.hpp"

int main() {
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n), y(m);
  cin >> x >> y;
  int max_x = max(X, max(x)), min_y = min(Y, min(y));
  cout << (max_x < min_y ? "No War" : "War") << endl;
}
