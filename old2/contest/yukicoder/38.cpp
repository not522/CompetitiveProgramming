#include "set.hpp"
#include "string.hpp"

int main() {
  int kr(in), kb(in);
  String s(in);
  Set<String> s1{""}, s2;
  for (char c : s) {
    for (auto s : s1) {
      if (c != 'W') {
        s2.insert(s);
      }
      s2.insert(s + c);
    }
    s1 = s2;
    s2.clear();
  }
  int res = 0;
  for (auto s : s1) {
    bool f = true;
    for (int i = 0; i < int(s.size()); ++i) {
      if (s[i] == 'R') {
        if (0 <= i - kr && s[i - kr] == 'R') {
          f = false;
        }
        if (i + kr < int(s.size()) && s[i + kr] == 'R') {
          f = false;
        }
      }
      if (s[i] == 'B') {
        if (0 <= i - kb && s[i - kb] == 'B') {
          f = false;
        }
        if (i + kb < int(s.size()) && s[i + kb] == 'B') {
          f = false;
        }
      }
    }
    if (f) {
      chmax(res, int(s.size()));
    }
  }
  cout << res << endl;
}
