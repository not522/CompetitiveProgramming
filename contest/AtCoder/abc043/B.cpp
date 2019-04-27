#include "string.hpp"

int main() {
  String s(in), t;
  for (char c : s) {
    switch (c) {
    case '0':
      t += '0';
      break;
    case '1':
      t += '1';
      break;
    case 'B':
      if (!t.empty()) {
        t.pop_back();
      }
      break;
    }
  }
  cout << t << endl;
}
