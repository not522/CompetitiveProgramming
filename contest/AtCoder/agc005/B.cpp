#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int64_t> a(n), b(n), c(n);
  cin >> a;
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] >= a[i]) {
      b[st.top()] = i - 1;
      st.pop();
    }
    st.emplace(i);
  }
  while (!st.empty()) {
    b[st.top()] = n - 1;
    st.pop();
  }
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && a[st.top()] > a[i]) {
      c[st.top()] = i + 1;
      st.pop();
    }
    st.emplace(i);
  }
  while (!st.empty()) {
    c[st.top()] = 0;
    st.pop();
  }
  int64_t res = 0;
  for (int i = 0; i < n; ++i) res += a[i] * (b[i] - i + 1) * (i - c[i] + 1);
  cout << res << endl;
}
