#include <climits>
#include <iostream>

using namespace std;

template<typename T> int least_bit(T n) {
  for (unsigned i = 0; i < sizeof(T) * CHAR_BIT; ++i) {
    if (n & 1ll << i) return i;
  }
  return -1;
}

template<typename T> int least_bit_fast(T n) {
  for (unsigned i = 0; i < sizeof(T) * CHAR_BIT; ++i) {
    if (n & 1ll << i) return i;
  }
  return -1;
}

template<typename T> int most_bit(T n) {
  for (int i = sizeof(T) * CHAR_BIT - 1; i >= 0; --i) {
    if (n & 1ll << i) return i;
  }
  return -1;
}

template<typename T> int count_bit(T n) {
  int r = 0;
  for (unsigned i = 0; i < sizeof(T) * CHAR_BIT; ++i) {
    if (n & 1ll << i) ++r;
  }
  return r;
}

template<typename T> void solve(string func) {
  T n;
  cin >> n;
  if (func == "least_bit") cout << least_bit(n) << endl;
  else if (func == "least_bit_fast") cout << least_bit_fast(n) << endl;
  else if (func == "most_bit") cout << most_bit(n) << endl;
  else cout << count_bit(n) << endl;
}

int main() {
  string func, t;
  cin >> func >> t;
  if (t == "int") solve<int>(func);
  else solve<int64_t>(func);
}
