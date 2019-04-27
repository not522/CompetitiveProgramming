#include "string.hpp"

int main() {
  String w(in);
  for (char c = 'a'; c <= 'z'; ++c) {
    if (w.count(c) % 2) {
      cout << false << endl;
      return 0;
    }
  }
  cout << true << endl;
}
