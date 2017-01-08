#pragma once
#include "bitwise.hpp"
#include "minmax.hpp"
#include "vector.hpp"

class Section : public Bitwise<Section> {
private:
  const static long long MIN = numeric_limits<long long>::min();
  const static long long MAX = numeric_limits<long long>::max();

  using VAL = vector<pair<long long, long long>>;

public:
  VAL v;

  Section() {}

  Section(long long a, long long b) {v.emplace_back(a, b);}

  Section operator&=(const Section& s) {
    VAL res;
    for (int i = 0, j = 0; i < (int)v.size() && j < (int)s.v.size(); ) {
      if (v[i].first < s.v[j].second && s.v[j].first < v[i].second) {
        res.emplace_back(max(v[i].first, s.v[j].first), min(v[i].second, s.v[j].second));
      }
      if (v[i].second < s.v[j].second) ++i;
      else ++j;
    }
    v = res;
    return *this;
  }

  Section operator|=(const Section& s) {
    v.insert(v.end(), s.v.begin(), s.v.end());
    sort(v);
    int p = 0;
    for (int i = 1; i < (int)v.size(); ++i) {
      if (v[p].second >= v[i].first) {
        chmax(v[p].second, v[i].second);
        v[i] = make_pair(MAX, MAX);
      } else {
        p = i;
      }
    }
    sort(v);
    unique(v);
    return *this;
  }

  Section operator^=(const Section& s) {
    Section a = *this, b = *this;
    a &= s;
    a.complement();
    b |= s;
    return *this = a &= b;
  }

  pair<long long, long long>& operator[](int i) {
    return v[i];
  }

  const pair<long long, long long>& operator[](int i) const {
    return v[i];
  }

  void complement() {
    VAL res;
    if (v[0].first != MIN) res.emplace_back(MIN, v[0].first);
    for (int i = 0; i < (int)v.size() - 1; ++i) res.emplace_back(v[i].second, v[i + 1].first);
    if (v.back().second != MAX) res.emplace_back(v.back().second, MAX);
  }

  long long first() const {
    return v[0].first;
  }

  long long second() const {
    return v[0].second;
  }

  long long size() const {
    long long res = 0;
    for (const auto& i : v) res += i.second - i.first - 1;
    return res;
  }
};

inline ostream& operator<<(ostream& os, const Section& s) {
  for (auto i : s.v) os << i.first << " " << i.second - 1 << endl;
  return os;
}

inline istream& operator>>(istream& is, Section& s) {
  long long a, b;
  is >> a >> b;
  s = Section(a, b + 1);
  return is;
}
