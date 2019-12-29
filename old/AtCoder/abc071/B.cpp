#include "string.hpp"
#include "vector.hpp"

int main() {
  String s(in);
  Vector<int> v(26);
  for (char c : s) {
    ++v[c - 'a'];
  }
  for (int i = 0; i < 26; ++i) {
    if (v[i] == 0) {
      cout << char(i + 'a') << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}
