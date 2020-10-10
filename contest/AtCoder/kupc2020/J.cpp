#include "vector.hpp"

int med(int v1, int v2, int v3) {
  if ((v1 < v2) == (v2 < v3)) {
    return v2;
  }
  if ((v1 < v3) == (v3 < v2)) {
    return v3;
  }
  return v1;
}

int query1(int i, int j, int k) {
  cout << "? 1 " << i << " " << j << " " << k << endl;
  return int(in);
}

int query2(int i, int j) {
  cout << "? 2 " << i << " " << j << endl;
  return int(in);
}

int main() {
  int n(in);
  Vector<Tuple<Vector<int>, int>> r;
  Vector<int> s;
  for (int i = 1; i <= 4; ++i) {
    for (int j = i + 1; j <= 4; ++j) {
      for (int k = j + 1; k <= 4; ++k) {
        int res = query1(i, j, k);
        r.emplace_back(Vector<int>({i, j, k}), res);
        s.emplace_back(res);
      }
    }
  }
  s.sort().unique();
  int low = s[0], high = s[1];
  int cnt[3][5]{};
  int li1 = -1, li2 = -1, hi1 = -1, hi2 = -1;
  for (const auto &[v, k] : r) {
    for (int i : v) {
      if (k == low) {
        ++cnt[0][i];
        if (cnt[0][i] == 2) {
          if (li1 == -1) {
            li1 = i;
          } else {
            li2 = i;
          }
        }
      } else {
        ++cnt[2][i];
        if (cnt[2][i] == 2) {
          if (hi1 == -1) {
            hi1 = i;
          } else {
            hi2 = i;
          }
        }
      }
    }
  }
  Vector<int> res(n);
  for (int i = 5; i <= n; ++i) {
    int res1 = query1(li1, hi1, i);
    if (res1 > low) {
      int res2 = query1(li1, hi2, i);
      if (res1 == res2) {
        res[i - 1] = res1;
      } else if (high == res1) {
        res[hi1 - 1] = high;
        hi1 = i;
        high = res2;
      } else {
        res[hi2 - 1] = high;
        hi2 = i;
        high = res1;
      }
    } else {
      int res2 = query1(li2, hi1, i);
      if (res1 == res2) {
        res[i - 1] = res1;
      } else if (low == res1) {
        res[li1 - 1] = low;
        li1 = i;
        low = res2;
      } else {
        res[li2 - 1] = low;
        li2 = i;
        low = res1;
      }
    }
  }
  if (query2(li1, li2) == li1) {
    res[li1 - 1] = 1;
    res[li2 - 1] = 2;
  } else {
    res[li1 - 1] = 2;
    res[li2 - 1] = 1;
  }
  if (query2(hi1, hi2) == hi1) {
    res[hi1 - 1] = n - 1;
    res[hi2 - 1] = n;
  } else {
    res[hi1 - 1] = n;
    res[hi2 - 1] = n - 1;
  }
  cout << "! ";
  res.output(" ");
}
