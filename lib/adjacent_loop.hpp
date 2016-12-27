#pragma once
#include "template.hpp"

template<int N> class AdjacentLoop {
private:
  static int dy(int i);
  static int dx(int i);

  struct Iterator {
    const int y, x, h, w;
    int val;

    Iterator(int y, int x, int h, int w, int val) : y(y), x(x), h(h), w(w), val(val) {
      for (; this->val < N; ++this->val) {
        int yy = y + dy(this->val);
        int xx = x + dx(this->val);
        if (0 <= yy && yy < h && 0 <= xx && xx < w) break;
      }
    }

    pair<int, int> operator*() {return make_pair(y + dy(val), x + dx(val));}

    bool operator!=(Iterator& itr) {return val < itr.val;}

    void operator++() {
      while (++val < N) {
        int yy = y + dy(val);
        int xx = x + dx(val);
        if (0 <= yy && yy < h && 0 <= xx && xx < w) break;
      }
    }
  };

  Iterator i, n;

public:
  AdjacentLoop(int y, int x, int h, int w) : i(y, x, h, w, 0), n(y, x, h, w, N) {}

  Iterator& begin() {return i;}

  Iterator& end() {return n;}
};

template<> int AdjacentLoop<2>::dy(int i) {
  constexpr int dy[]{0, 1};
  return dy[i];
}

template<> int AdjacentLoop<2>::dx(int i) {
  constexpr int dx[]{1, 0};
  return dx[i];
}

template<> int AdjacentLoop<4>::dy(int i) {
  constexpr int dy[]{0, -1, 0, 1};
  return dy[i];
}

template<> int AdjacentLoop<4>::dx(int i) {
  constexpr int dx[]{1, 0, -1, 0};
  return dx[i];
}

template<> int AdjacentLoop<5>::dy(int i) {
  constexpr int dy[]{0, -1, 0, 1, 0};
  return dy[i];
}

template<> int AdjacentLoop<5>::dx(int i) {
  constexpr int dx[]{1, 0, -1, 0, 0};
  return dx[i];
}

template<> int AdjacentLoop<8>::dy(int i) {
  constexpr int dy[]{-1, -1, -1, 0, 0, 1, 1, 1};
  return dy[i];
}

template<> int AdjacentLoop<8>::dx(int i) {
  constexpr int dx[]{-1, 0, 1, -1, 1, -1, 0, 1};
  return dx[i];
}

template<> int AdjacentLoop<9>::dy(int i) {
  constexpr int dy[]{-1, -1, -1, 0, 0, 0, 1, 1, 1};
  return dy[i];
}

template<> int AdjacentLoop<9>::dx(int i) {
  constexpr int dx[]{-1, 0, 1, -1, 0, 1, -1, 0, 1};
  return dx[i];
}
