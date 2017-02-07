#include "template.hpp"

int main() {
  const string s = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
  int i = 0, w;
  cin >> w;
  for (i = 0; i < 51; i += w) cout << s.substr(i, w) << endl;
}
