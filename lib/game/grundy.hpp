#include "template.hpp"

template<typename T> class Grundy {
private:
  map<T, int> grundy;

public:
  int solve(T t) {
    if (grundy.count(t)) return grundy[t];
    set<int> s;
    for (auto g : t.next()) s.insert(solve(g));
    for (int i = 0; ; ++i) {
      if (s.count(i) == 0) return grundy[t] = i;
    }
  }

  template<typename S> int solve(S s) {
    int g = 0;
    for (auto t : s) g ^= solve(t);
    return g;
  }
};
