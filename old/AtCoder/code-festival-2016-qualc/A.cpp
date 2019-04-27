#include "template.hpp"

int main() {
  string s;
  cin >> s;
  if (s.find('C') != string::npos && s.find('F') != string::npos && s.find('C') < s.find_last_of('F')) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
