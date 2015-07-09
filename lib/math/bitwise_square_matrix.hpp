#pragma once
#include "math/bitwise.hpp"
#include "math/square_matrix.hpp"

template<> SquareMatrix<Bitwise<unsigned int>> SquareMatrix<Bitwise<unsigned int>>::identity() const {
  SquareMatrix res(this->size());
  for (int i = 0; i < this->size(); ++i) res[i][i] = numeric_limits<unsigned int>::max();
  return res;
}
