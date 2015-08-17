#include "binary_search.hpp"

int main() {
  int cnt = 0;
  auto f = [&](int m){
    cout << "? " << m - cnt << endl;
    ++cnt;
    int res;
    cin >> res;
    return res >= 0;
  };
  cout << "! " << binarySearch(f, 10, f(100) ? 1e9 + 1 : 101) << endl;
}
