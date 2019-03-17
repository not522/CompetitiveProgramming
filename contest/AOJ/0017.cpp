#include "string.hpp"

int main() {
  auto f = [](char c) -> char {
    if (isalpha(c)) {
      if (c != 'z') {
        return c + 1;
      }
      return 'a';
    }
    return c;
  };
  for (String str; getline(cin, str);) {
    for (int i = 0; i < 26; ++i) {
      str = str.transform(f);
      if (str.in("that") || str.in("this") || str.in("the")) {
        cout << str << endl;
      }
    }
  }
}
