#include "template.hpp"

struct Question {
  array<int, 4> v;
  bool res;
};

int main() {
  int n;
  cin >> n;
  vector<Question> q(n);
  for (int i = 0; i < n; ++i) {
    for (int& j : q[i].v) cin >> j;
    string s;
    cin >> s;
    q[i].res = (s == "YES");
  }
  for (int i = 0; i < 10; ++i) {
    auto f = [&](Question q){return (find(q.v.begin(), q.v.end(), i) != q.v.end()) == q.res;};
    if (all_of(q.begin(), q.end(), f)) cout << i << endl;
  }
}
