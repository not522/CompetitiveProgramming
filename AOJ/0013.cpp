#include "template.hpp"

int main() {
  int n;
  stack<int> s;
  while (cin >> n) {
    if (n) {
      s.push(n);
    } else {
      cout << s.top() << endl;
      s.pop();
    }
  }
}
