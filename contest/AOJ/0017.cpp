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
  for (String str; str = String::getline(), !in.eof;) {
    for (int i = 0; i < 26; ++i) {
      str = str.transform(f);
      if (str.has("that") || str.has("this") || str.has("the")) {
        cout << str << endl;
      }
    }
  }
}
