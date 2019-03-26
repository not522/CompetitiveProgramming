#include "string.hpp"

int main() {
  set_bool_name("You can win", "You will lose");
  String s(in), t(in);
  String atcoder = "atcoder";
  for (int i = 0; i < s.size(); ++i) {
    if ((s[i] != t[i]) && (s[i] != '@' || !atcoder.contains(t[i])) &&
        (t[i] != '@' || !atcoder.contains(s[i]))) {
      cout << false << endl;
      return 0;
    }
  }
  cout << true << endl;
}
