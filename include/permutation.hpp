#pragma once
#include "vector.hpp"

class Permutation {
private:
  int id;
  Vector<int> perm;

public:
  Permutation(int n) : id(0), perm(iota<int>(n)) {}

  Vector<int> operator*() {
    return perm;
  }

  bool operator!=(const Permutation& itr) const {
    return id != itr.id;
  }

  void operator++() {
    id = perm.next_permutation() ? id + 1 : -1;
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
