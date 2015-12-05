#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<string> a(n);
  cin >> a;
  sort(a.begin(), a.end(), [](string a, string b){return a + b > b + a;});
  cout << accumulate(a.begin(), a.end(), string()) << endl;
}
