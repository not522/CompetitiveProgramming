#include "template.hpp"

int main() {
  string str;
  while (getline(cin, str)) {
    for (int i = 0; i < 26; ++i) {
      for (char& c : str) {
        if (isalpha(c)) {
          if (c != 'z') ++c;
          else c = 'a';
        }
      }
      if (str.find("that") != string::npos || str.find("this") != string::npos || str.find("the") != string::npos) {
        cout << str << endl;
      }
    }
  }
}
