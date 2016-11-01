#include "vector.hpp"

int main() {
  vector<int> d(3);
  int s;
  cin >> d >> s;
  cout << (accumulate(d) < 2 || s ? "SURVIVED" : "DEAD") << endl;
}
