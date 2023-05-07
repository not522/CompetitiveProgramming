#include "string.hpp"

struct Card {
  String s;
  int suit, number;

  Card() {}

  Card(const String &s) : s(s) {
    switch (s[0]) {
    case 'D':
      suit = 0;
      break;
    case 'C':
      suit = 1;
      break;
    case 'H':
      suit = 2;
      break;
    case 'S':
      suit = 3;
      break;
    }
    switch (s[1]) {
    case 'A':
      number = 1;
      break;
    case 'T':
      number = 10;
      break;
    case 'J':
      number = 11;
      break;
    case 'Q':
      number = 12;
      break;
    case 'K':
      number = 13;
      break;
    default:
      number = s[1] - '0';
      break;
    }
  }

  bool operator<(const Card &card) const {
    return suit != card.suit ? suit < card.suit : number < card.number;
  }
};

int main() {
  int n(in);
  Vector<Card> c(n);
  for (auto &i : c) {
    String s(in);
    i = s;
  }
  auto f = [](const Card &c) { return c.s; };
  c.sort().transform(f).output(" ");
}
