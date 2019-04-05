#include "string.hpp"
#include "tuple.hpp"
#include "vector.hpp"

void output(int s, int e) {
  cout << ZeroPadding(4) << s << "-" << ZeroPadding(4) << e << endl;
}

int main() {
  int n(in);
  Vector<Tuple<int, int>> d;
  for (int i = 0; i < n; ++i) {
    int s(in);
    in.ignore();
    int e(in);
    s -= s % 5;
    e += 4;
    e -= e % 5;
    if (e % 100 == 60) {
      e += 40;
    }
    d.emplace_back(s, e);
  }
  d.sort();
  int t = 0;
  for (int i = 1; i < n; ++i) {
    if (d[t].get<1>() >= d[i].get<0>()) {
      d[t].get<1>() = max(d[t].get<1>(), d[i].get<1>());
    } else {
      output(d[t].get<0>(), d[t].get<1>());
      t = i;
    }
  }
  output(d[t].get<0>(), d[t].get<1>());
}
