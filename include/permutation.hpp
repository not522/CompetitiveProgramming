#pragma once
#include "vector.hpp"

class Permutation {
private:
  int id;
  vector<int> perm;

public:
  Permutation(int n) : id(0), perm(n) {
    iota(perm);
  }

  vector<int> operator*() {
    return perm;
  }

  bool operator!=(const Permutation& itr) const {
    return id != itr.id;
  }

  void operator++() {
    id = next_permutation(perm) ? id + 1 : -1;
  }

  Permutation& begin() {
    return *this;
  }

  Permutation& end();

  static Permutation makeEnd() {
    Permutation p(0);
    p.id = -1;
    return p;
  }
};

Permutation permutation_end = Permutation::makeEnd();

Permutation& Permutation::end() {
  return permutation_end;
}
