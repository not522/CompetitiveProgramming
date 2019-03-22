#include "string.hpp"

int main() {
  for (String line; line = in, !in.eof;) {
    auto d = line.split(',').transform(cast<String, int>());
    auto l = d.subvector(10), v = d.subvector(10, 12);
    auto s = l.partial_sum();
    for (int i = 0; i < 10; ++i) {
      if (s[i] * v[1] >= (s.back() - s[i]) * v[0]) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}
