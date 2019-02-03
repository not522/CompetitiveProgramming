#include "template.hpp"

int main() {
  int s;
  cin >> s;
  set<int> st;
  for (int i = 1; ; ++i) {
    if (st.count(s)) {
      cout << i << endl;
      return 0;
    }
    st.emplace(s);
    if (s % 2) s = 3 * s + 1;
    else s /= 2;
  }
}
