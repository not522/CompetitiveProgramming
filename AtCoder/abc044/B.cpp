#include "template.hpp"

int main() {
  string w;
  cin >> w;
  for (char c = 'a'; c <= 'z'; ++c) {
    if (count(w.begin(), w.end(), c) % 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
