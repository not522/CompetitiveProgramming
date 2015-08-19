#include "dp/levenshtein_distance.hpp"

int main() {
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  cout << levenshteinDistance(s, t) << endl;
}
