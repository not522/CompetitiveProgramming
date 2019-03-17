#include "stack.hpp"

int main() {
  Stack<int> s;
  for (int n; cin >> n;) {
    if (n) {
      s.push(n);
    } else {
      cout << s.top() << endl;
    }
  }
}
