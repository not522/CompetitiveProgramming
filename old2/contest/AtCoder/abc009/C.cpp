#include "string.hpp"

int main() {
  int n(in), k(in);
  String s(in);
  int cnt1[26] = {};
  int cnt2[26] = {};
  for (int i = 0; i < n; ++i) {
    ++cnt1[s[i] - 'a'];
    ++cnt2[s[i] - 'a'];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (cnt2[j] == 0) {
        continue;
      }
      int kk = k;
      if (s[i] - 'a' != j) {
        if (cnt1[j] >= cnt2[j]) {
          --kk;
        }
        if (cnt1[s[i] - 'a'] <= cnt2[s[i] - 'a']) {
          --kk;
        }
        if (kk < 0) {
          continue;
        }
        k = kk;
      }
      --cnt1[s[i] - 'a'];
      --cnt2[j];
      cout << char(j + 'a');
      break;
    }
  }
  cout << endl;
}
