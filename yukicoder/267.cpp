#include "string/to_string.hpp"

struct Card {
  string s;
  int suit, number;

  Card() {}

  Card(const string& s) : s(s) {
    switch (s[0]) {
    case 'D': suit = 0; break;
    case 'C': suit = 1; break;
    case 'H': suit = 2; break;
    case 'S': suit = 3; break;
    }
    switch (s[1]) {
    case 'A': number =  1; break;
    case 'T': number = 10; break;
    case 'J': number = 11; break;
    case 'Q': number = 12; break;
    case 'K': number = 13; break;
    default : number = s[1] - '0'; break;
    }
  }

  bool operator<(const Card& card) const {
    return suit != card.suit ? suit < card.suit : number < card.number;
  }
};

string to_string(const Card& card) {
  return card.s;
}

int main() {
  int n;
  cin >> n;
  vector<Card> c(n);
  for (auto& i : c) {
    string s;
    cin >> s;
    i = s;
  }
  sort(c.begin(), c.end());
  cout << to_string(c) << endl;
}
