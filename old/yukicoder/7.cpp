#include "math/prime.hpp"
#include "game/min_max.hpp"

class Game : public MinMax<int, int, true> {
private:
  vector<int> mem;
  vector<int> primes;

  int eval(const int&) const {
    return 1;
  }

  vector<int> next(const int& state) const {
    vector<int> res;
    for (int p : primes) {
      if (p > state) break;
      res.emplace_back(state - p);
    }
    return res;
  }

  bool used(const int& state) const {
    return mem[state] != 0;
  }

  int memo(const int& state) {
    return mem[state];
  }

  void use(const int& state, const int& score) {
    mem[state] = score;
  }

public:
  Game(int n) : mem(n + 1) {
    Prime prime;
    for (int i = 0; i <= n; ++i) if (prime.isPrime(i)) primes.emplace_back(i);
  }
};

int main() {
  int n;
  cin >> n;
  Game game(n);
  cout << (game.solve(n) == 1 ? "Win" : "Lose") << endl;
}
