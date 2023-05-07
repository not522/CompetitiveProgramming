#pragma once
#include "vector.hpp"

class PermutationMatrix : public Vector<int> {
public:
  PermutationMatrix(int n) : Vector<int>(n) {}

  PermutationMatrix(const Vector<int> &v) : Vector<int>(v) {}

  PermutationMatrix &operator*=(const PermutationMatrix &m) {
    PermutationMatrix res(size());
    for (int i = 0; i < size(); ++i) {
      res[i] = (*this)[m[i]];
    }
    return *this = res;
  }

  PermutationMatrix operator*(const PermutationMatrix &m) const {
    return PermutationMatrix(*this) *= m;
  }

  PermutationMatrix &operator/=(const PermutationMatrix &m) {
    return *this *= m.inverse();
  }

  PermutationMatrix operator/(const PermutationMatrix &m) const {
    return PermutationMatrix(*this) /= m;
  }

  static PermutationMatrix identity(int n) { return iota<int>(n); }

  PermutationMatrix inverse() const {
    PermutationMatrix inv(size());
    for (int i = 0; i < size(); ++i) {
      inv[(*this)[i]] = i;
    }
    return inv;
  }
};
