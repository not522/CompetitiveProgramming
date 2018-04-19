#pragma once
#include "template.hpp"

class UnionFind {
private:
  int n;
  vector<int> a;
public:
  UnionFind(int n) : n(n), a(n, -1) {}
  int find(int x) {return a[x] < 0 ? x : (a[x] = find(a[x]));}
  bool equal(int x, int y) {return find(x) == find(y);}
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (a[x] > a[y]) swap(x, y);
    a[x] += a[y];
    a[y] = x;
    --n;
  }
  int size() {return n;}
  int size(int x) {return -a[find(x)];}
  bool isRoot(int x) {return find(x) == x;}
  vector<vector<int>> groups() {
    vector<vector<int>> r(a.size()), res;
    for (unsigned i = 0; i < a.size(); ++i) r[find(i)].emplace_back(i);
    for (auto&& i : r) if (!i.empty()) res.emplace_back(move(i));
    return res;
  }
};
