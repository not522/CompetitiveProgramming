#include "string.hpp"

struct Question {
  Vector<int> v;
  bool res;

  Question() : v(4) {}
};

int main() {
  int n(in);
  Vector<Question> q(n);
  for (int i = 0; i < n; ++i) {
    for (int &j : q[i].v) {
      j = in;
    }
    String s(in);
    q[i].res = (s == "YES");
  }
  for (int i = 0; i < 10; ++i) {
    auto f = [&](Question q) {
      return (find(q.v.begin(), q.v.end(), i) != q.v.end()) == q.res;
    };
    if (q.all_of(f)) {
      cout << i << endl;
    }
  }
}
