#include "vector.hpp"

int main() {
  string s;
  int k;
  cin >> s >> k;
  vector<string> substr;
  for (unsigned i = 0; i < s.size(); ++i) {
    for (unsigned j = 1; i + j <= s.size() && j <= 5u; ++j) {
      substr.emplace_back(s.substr(i, j));
    }
  }
  sort(substr);
  unique(substr);
  cout << substr[k - 1] << endl;
}
