#pragma once
#include "arithmetic.hpp"

class PermutationMatrix : public arithmetic::Multiplication<PermutationMatrix>, public arithmetic::Division<PermutationMatrix> {
private:
  vector<int> val;

public:
  PermutationMatrix(size_t Nb) : val(Nb) {}

  int& operator[](int n) {
    return val[n];
  }
	
  PermutationMatrix operator*=(const PermutationMatrix& m) {
    PermutationMatrix res(size());
    for (size_t i = 0; i < size(); ++i) res[i] = val[const_cast<PermutationMatrix&>(m)[i]];
    return *this = res;
  }

	PermutationMatrix operator/=(const PermutationMatrix& m) {
		return *this *= m.inverse();
	}

  size_t size() const {
    return val.size();
  }

  PermutationMatrix identity() const {
    PermutationMatrix res(size());
    for (size_t i = 0; i < size(); ++i) res[i] = i;
    return res;
  }

  PermutationMatrix inverse() const {
    PermutationMatrix inv(size());
    for (size_t i = 0; i < size(); ++i) inv[val[i]] = i;
    return inv;
  }
};
