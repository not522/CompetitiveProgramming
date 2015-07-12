#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  cout << ceil((double)accumulate(a.begin(), a.end(), 0) / count_if(a.begin(), a.end(), [](int i){return i != 0;})) << endl;
}
