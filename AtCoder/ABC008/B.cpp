#include "template.hpp"

int main() {
  int n;
  cin >> n;
  map<string, int> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ++m[s];
  }
  cout << max_element(m.begin(), m.end(), [](pair<string, int> a, pair<string, int> b){return a.second < b.second;})->first << endl;
}
