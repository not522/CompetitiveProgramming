#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> p(m), id(m);
  vector<int> c(n);
  for (int i = 0; i < m; ++i) {
    cin >> get<1>(p[i]) >> get<0>(p[i]);
    get<2>(p[i]) = i;
  }
  sort(p);
  for (int i = 0; i < m; ++i) id[i] = make_tuple(get<2>(p[i]), get<1>(p[i]), ++c[get<1>(p[i])]);
  sort(id);
  for (int i = 0; i < m; ++i) {
    cout << setw(6) << setfill('0') << get<1>(id[i]) << setw(6) << setfill('0') << get<2>(id[i]) << endl;
  }
}
