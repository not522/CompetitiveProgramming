#include "count.hpp"

int main() {
  string s;
  cin >> s;
  auto c = count(s);
  int even = 0, odd = 0;
  for (auto i : c) {
    even += i.second / 2;
    odd += i.second % 2;
  }
  cout << (odd ? even / odd * 2 + 1 : s.size()) << endl;
}
