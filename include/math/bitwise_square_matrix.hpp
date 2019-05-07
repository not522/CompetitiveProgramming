#pragma once
#include "math/bitwise.hpp"
#include "math/square_matrix.hpp"

template <>
SquareMatrix<Bitwise<unsigned int>>
SquareMatrix<Bitwise<unsigned int>>::identity(int n) {
  SquareMatrix res(n);
  for (int i = 0; i < n; ++i) {
    res[i][i] = std::numeric_limits<unsigned int>::max();
  }
  return res;
}
