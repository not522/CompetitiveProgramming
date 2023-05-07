#include "set.hpp"
#include "string.hpp"

bool isVowel(char c) {
  return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
}

int main() {
  String str = "inabameguru";
  str.sort();
  Set<String> s;
  do {
    if (!isVowel(str.back())) {
      continue;
    }
    char p = 'a';
    bool ok = true;
    for (char c : str) {
      if (!isVowel(p) && !isVowel(c)) {
        ok = false;
      }
      p = c;
    }
    if (ok) {
      s.insert(str);
    }
  } while (str.next_permutation());
  int n(in);
  for (int i = 0; i < n; ++i) {
    s.erase(String(in));
  }
  if (s.empty()) {
    cout << "NO" << endl;
  } else {
    cout << *(s.begin()) << endl;
  }
}
