#include "dp/digit_dp.hpp"
#include "math/mint.hpp"

class Number : public DigitDP<Mint, pair<int, vector<Mint>>> {
private:
  int d;

  void step(int n) {
    curr = make_pair((prev.first + n) % d, vector<Mint>(d));
    for (int i = 0; i < d; ++i) {
      for (int j = 0; j < 10; ++j) {
        curr.second[(i + j) % d] += prev.second[i];
      }
    }
    for (int i = 0; i < n; ++i) ++curr.second[(prev.first + i) % d];
  }

  Mint result() {return curr.second[0] + (curr.first % d ? -1 : 0);}

public:
  Number(string n, int d) : DigitDP<Mint, pair<int, vector<Mint>>>(n), d(d) {
    curr = make_pair(0, vector<Mint>(d));
  }
};

int main() {
  int d;
  string n;
  cin >> d >> n;
  Number number(n, d);
  cout << number.solve() << endl;
}
