#pragma once
#include "bitwise.hpp"
#include "vector.hpp"

class Section : public Bitwise<Section> {
private:
  const static int64_t MIN = std::numeric_limits<int64_t>::lowest();
  const static int64_t MAX = std::numeric_limits<int64_t>::max();

  using VAL = vector<pair<int64_t, int64_t>>;

public:
  VAL v;

  Section() {}

  Section(int64_t a, int64_t b) { v.emplace_back(a, b); }

  Section &operator&=(const Section &s) {
    VAL res;
    for (unsigned i = 0, j = 0; i < v.size() && j < s.v.size();) {
      if (v[i].first < s.v[j].second && s.v[j].first < v[i].second) {
        res.emplace_back(max(v[i].first, s.v[j].first),
                         min(v[i].second, s.v[j].second));
      }
      if (v[i].second < s.v[j].second) {
        ++i;
      } else {
        ++j;
      }
    }
    v = res;
    return *this;
  }

  Section &operator|=(const Section &s) {
    v.insert(v.end(), s.v.begin(), s.v.end());
    sort(v);
    int p = 0;
    for (unsigned i = 1; i < v.size(); ++i) {
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

  Section &operator^=(const Section &s) {
    Section a = *this, b = *this;
    a &= s;
    a.complement();
    b |= s;
    return *this = a &= b;
  }

  pair<int64_t, int64_t> &operator[](int i) { return v[i]; }

  const pair<int64_t, int64_t> &operator[](int i) const { return v[i]; }

  void complement() {
    VAL res;
    if (v[0].first != MIN) {
      res.emplace_back(MIN, v[0].first);
    }
    for (unsigned i = 0; i + 1 < v.size(); ++i) {
      res.emplace_back(v[i].second, v[i + 1].first);
    }
    if (v.back().second != MAX) {
      res.emplace_back(v.back().second, MAX);
    }
  }

  int64_t first() const { return v[0].first; }

  int64_t second() const { return v[0].second; }

  int64_t size() const {
    int64_t res = 0;
    for (const auto &i : v) {
      res += i.second - i.first - 1;
    }
    return res;
  }
};

ostream &operator<<(ostream &os, const Section &s) {
  for (auto i : s.v) {
    os << i.first << " " << i.second - 1 << endl;
  }
  return os;
}

istream &operator>>(istream &is, Section &s) {
  int64_t a, b;
  is >> a >> b;
  s = Section(a, b + 1);
  return is;
}
