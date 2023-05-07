#include "set.hpp"
#include "string.hpp"

int main() {
  String s(in);
  int k(in);
  Set<String> st;
  for (int i = 0; i <= s.size() - k; ++i) {
    st.emplace(s.substr(i, k));
  }
  cout << st.size() << endl;
}
