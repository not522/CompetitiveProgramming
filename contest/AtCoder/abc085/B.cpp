#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  cin >> d;
  cout << kinds(d) << endl;
}
