#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  map<int, int> c;
  for (int i : a) ++c[i];
  for (const auto& i : c) cout << i.first << " " << i.second << endl;
}
