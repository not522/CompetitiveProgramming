#include "binary_search.hpp"

class Shooting : public BinarySearch {
private:
  int n;
  vector<int> h, s;

  bool valid(long long m) {
    vector<long long> v;
    for (int i = 0; i < n; ++i) v.emplace_back((m - h[i]) / s[i]);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
      if (v[i] < i || h[i] > m) return false;
    }
    return true;
  }

public:
  Shooting(const int n, const vector<int>& h, const vector<int>& s) : BinarySearch(numeric_limits<long long>::max(), 0), n(n), h(h), s(s) {}
};

int main() {
  int n;
  cin >> n;
  vector<int> h(n), s(n);
  for (int i = 0; i < n; ++i) cin >> h[i] >> s[i];
  Shooting shooting(n, h, s);
  cout << shooting.solve() << endl;
}
