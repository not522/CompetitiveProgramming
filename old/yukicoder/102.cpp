#include "game/grundy.hpp"
#include "vector.hpp"

class Card {
private:
  int card;

public:
  Card() {}

  Card(int card) : card(card) {}

  Card(Input in) : card(in) {}

  Vector<Card> next() {
    Vector<Card> res;
    if (card >= 1) {
      res.emplace_back(card - 1);
    }
    if (card >= 2) {
      res.emplace_back(card - 2);
    }
    if (card >= 3) {
      res.emplace_back(card - 3);
    }
    return res;
  }

  bool operator<(const Card& c) const {
    return card < c.card;
  }
};

int main() {
  setBoolName("Taro", "Jiro");
  Vector<Card> n(4, in);
  Grundy<Card> grundy;
  cout << grundy.solve(n) << endl;
}
