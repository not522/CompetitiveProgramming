#include "template.hpp"

bool isVowel(char c) {
  return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
}

int main() {
  string str = "inabameguru";
  sort(str.begin(), str.end());
  set<string> s;
  do {
    if (!isVowel(str.back())) continue;
    char p = 'a';
    bool ok = true;
    for (char c : str) {
      if (!isVowel(p) && !isVowel(c)) ok = false;
      p = c;
    }
    if (ok) s.insert(str);
  } while (next_permutation(str.begin(), str.end()));
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    s.erase(str);
  }
  if (s.empty()) cout << "NO" << endl;
  else cout << *(s.begin()) << endl;
}
