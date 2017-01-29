#include "template.hpp"

int main() {
  int n;
  cin >> n;
  const string s[10] = {"zr", "bc", "dw", "tj", "fq", "lv", "sx", "pm", "hk", "ng"};
  vector<string> res;
  for (int i = 0; i < n; ++i) {
    string w, r;
    cin >> w;
    for (char c : w) {
      for (int i = 0; i < 10; ++i) {
        if (s[i].find(tolower(c)) != string::npos) r += to_string(i);
      }
    }
    if (!r.empty()) res.emplace_back(r + ' ');
  }
  if (!res.empty()) res.back().pop_back();
  for (const auto& r : res) cout << r;
  cout << endl;
}
