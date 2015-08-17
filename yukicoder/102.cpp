#include "game/grundy.hpp"

class Card {
private:
  int card;

public:
  Card() {}

  Card(int card) : card(card) {}

  vector<Card> next() {
    vector<Card> res;
    if (card >= 1) res.emplace_back(card - 1);
    if (card >= 2) res.emplace_back(card - 2);
    if (card >= 3) res.emplace_back(card - 3);
    return res;
  }

  bool operator<(const Card& c) const {
    return card < c.card;
  }
};

int main() {
  vector<Card> n(4);
  for (auto& i : n) {
    int j;
    cin >> j;
    i = j;
  }
  Grundy<Card> grundy;
  cout << (grundy.solve(n) ? "Taro" : "Jiro") << endl;
}
