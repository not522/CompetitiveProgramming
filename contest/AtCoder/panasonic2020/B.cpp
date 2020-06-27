#include  "math.hpp"

int main() {
  int64_t h(in), w(in);
  if (h == 1 || w == 1) {
    cout << 1 << endl;
  } else {
    cout << ceil<int64_t>(h * w, 2) << endl;
  }
}
