#include "bit_operation.hpp"

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
