#pragma once
#include "arithmetic.hpp"

template<typename T> class Polynomial : public Arithmetic<Polynomial<T>>, public arithmetic::Modulus<Polynomial<T>> {
private:
  vector<T> val;

  void normalize() {
    while (val.size() > 1u && val.back() == 0) val.pop_back();
    if (val.empty()) val.emplace_back(0);
  }

public:
	Polynomial() {
    normalize();
  }

	Polynomial(const vector<T>& val) : val(val) {
    normalize();
  }

  Polynomial(const int n, const T val) : val(vector<T>(n, val)) {}

	Polynomial operator+=(const Polynomial& p) {
    for (int i = 0; i < p.size(); ++i) {
      if (int(val.size()) == i) val.emplace_back(p[i]);
      else val[i] += p[i];
    }
    normalize();
		return *this;
	}

	Polynomial operator-=(const Polynomial& p) {
    for (int i = 0; i < p.size(); ++i) {
      if (int(val.size()) == i) val.emplace_back(-p[i]);
      else val[i] -= p[i];
    }
    normalize();
		return *this;
	}

  // TODO FFT
	Polynomial operator*=(const Polynomial& p) {
		Polynomial res;
    for (int i = 0; i < size(); ++i) {
      for (int j = 0; j < p.size(); ++j) {
        res[i + j] += val[i] * p[j];
      }
    }
		*this = res;
    normalize();
    return *this;
	}

  Polynomial operator/=(const Polynomial& p) {
    Polynomial res;
    for (int i = size() - p.size(); i >= 0; --i) {
      res[i] = val[p.size() + i - 1] / p.back();
      for (int j = 0; j < p.size(); ++j) val[i + j] -= res[i] * p[j];
    }
    *this = res;
    normalize();
    return *this;
  }

  Polynomial operator%=(const Polynomial& p) {
    for (int i = size() - p.size(); i >= 0; --i) {
      T d = val[p.size() + i - 1] / p.back();
      for (int j = 0; j < p.size(); ++j) val[i + j] -= d * p[j];
    }
    normalize();
    return *this;
  }

  T& operator[](int i) {
    if (i >= int(val.size())) val.resize(i + 1, 0);
    return val[i];
  }

  const T& operator[](int i) const {
    return val[i];
  }

  int size() const {
    return val.size();
  }

  T& back() {
    return val.back();
  }

  const T& back() const {
    return val.back();
  }

  typename vector<T>::iterator begin() {
    return val.begin();
  }

  typename vector<T>::iterator end() {
    return val.end();
  }

  Polynomial identity() const {
    return Polynomial(1, 1);
  }
};
