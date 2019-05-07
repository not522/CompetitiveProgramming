#pragma once
#include "tuple.hpp"
#include "vector.hpp"

template <int N> class AdjacentLoop {
private:
  const static Vector<int> dy, dx;

  struct Iterator {
    const int y, x, h, w;
    int val;

    Iterator(int y, int x, int h, int w, int val)
        : y(y), x(x), h(h), w(w), val(val) {
      for (; this->val < N; ++this->val) {
        int yy = y + dy[this->val];
        int xx = x + dx[this->val];
        if (0 <= yy && yy < h && 0 <= xx && xx < w) {
          break;
        }
      }
    }

    Tuple<int, int> operator*() { return makeTuple(y + dy[val], x + dx[val]); }

    bool operator!=(Iterator &itr) { return val < itr.val; }

    void operator++() {
      while (++val < N) {
        int yy = y + dy[val];
        int xx = x + dx[val];
        if (0 <= yy && yy < h && 0 <= xx && xx < w) {
          break;
        }
      }
    }
  };

  Iterator i, n;

public:
  AdjacentLoop(int y, int x, int h, int w)
      : i(y, x, h, w, 0), n(y, x, h, w, N) {}

  Iterator &begin() { return i; }

  Iterator &end() { return n; }
};

template <> const Vector<int> AdjacentLoop<2>::dy = {{0, 1}};
template <> const Vector<int> AdjacentLoop<2>::dx = {{1, 0}};

template <> const Vector<int> AdjacentLoop<4>::dy = {{0, -1, 0, 1}};
template <> const Vector<int> AdjacentLoop<4>::dx = {{1, 0, -1, 0}};

template <> const Vector<int> AdjacentLoop<5>::dy = {{0, -1, 0, 1, 0}};
template <> const Vector<int> AdjacentLoop<5>::dx = {{1, 0, -1, 0, 0}};

template <>
const Vector<int> AdjacentLoop<8>::dy = {{-1, -1, -1, 0, 0, 1, 1, 1}};
template <>
const Vector<int> AdjacentLoop<8>::dx = {{-1, 0, 1, -1, 1, -1, 0, 1}};

template <>
const Vector<int> AdjacentLoop<9>::dy = {{-1, -1, -1, 0, 0, 0, 1, 1, 1}};
template <>
const Vector<int> AdjacentLoop<9>::dx = {{-1, 0, 1, -1, 0, 1, -1, 0, 1}};
