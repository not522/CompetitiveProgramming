#include "vector.hpp"
#include "string/split.hpp"

int main() {
  string s;
  cin >> s;
  cout << count_if(split(s, '+'), [](string s){return !in(split(s, '*'), string("0"));}) << endl;
}
