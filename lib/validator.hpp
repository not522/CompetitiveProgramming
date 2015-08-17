#pragma once
#include "template.hpp"

class Validator {
private:
  bool unread;
  char prv;

  bool isSeparator(char c) {
    if (c == ' ') return true;
    if (c == '\n') return true;
    if (c == '\t') return true;
    if (c == EOF) return true;
    return false;
  }

  void back() {
    assert(unread == false);
    unread = true;
  }

public:
  const static int LOWER = 1;
  const static int UPPER = 2;
  const static int DIGIT = 4;
  const static int SYMBOL = 8;

  Validator() {
    unread = false;
  }

  ~Validator() {
    assert(readChar() == EOF);
  }

  char readChar() {
    if (unread) {
      unread = false;
      return prv;
    }
    return prv = getchar();
  }

  int readInt() {
    char c = readChar();
    long long n;
    if (c == '-') {
      c = readChar();
      assert('1' <= c && c <= '9');
      n = -(c - '0');
    } else {
      assert('0' <= c && c <= '9');
      n = c - '0';
    }
    if (n == 0) {
      assert(!isdigit(readChar()));
      back();
      return 0;
    }
    while (true) {
      c = readChar();
      if(!isdigit(c)) {
        back();
        break;
      }
      if (n > 0) n = n * 10 + c - '0';
      else n = n * 10 - (c - '0');
      assert(numeric_limits<int>::min() <= n && n <= numeric_limits<int>::max());
    }
    return n;
  }

  long long readLong() {
    char c = readChar();
    __int128 n;
    if (c == '-') {
      c = readChar();
      assert('1' <= c && c <= '9');
      n = -(c - '0');
    } else {
      assert('0' <= c && c <= '9');
      n = c - '0';
    }
    if (n == 0) {
      assert(!isdigit(readChar()));
      back();
      return 0;
    }
    while (true) {
      c = readChar();
      if(!isdigit(c)) {
        back();
        break;
      }
      if (n > 0) n = n * 10 + c - '0';
      else n = n * 10 - (c - '0');
      assert(numeric_limits<long long>::min() <= n && n <= numeric_limits<long long>::max());
    }
    return n;
  }

  string readString() {
    string s;
    char c;
    while (!isSeparator(c = readChar())) s += c;
    back();
    return s;
  }

  string readLine() {
    string s;
    char c;
    while ((c = readChar()) != '\n') s += c;
    back();
    return s;
  }
} validator;

int readInt(int a, int b) {
  int n = validator.readInt();
  assert(a <= n && n <= b);
  return n;
}

long long readLong(long long a, long long b) {
  auto n = validator.readLong();
  assert(a <= n && n <= b);
  return n;
}

string readString(int flag, int a, int b) {
  string s = validator.readString();
  assert(a <= (int)s.size() && (int)s.size() <= b);
  for (const auto& c : s) {
    assert(isgraph(c));
    if (islower(c)) {
      assert(flag & Validator::LOWER);
    } else if (isupper(c)) {
      assert(flag & Validator::UPPER);
    } else if (isdigit(c)) {
      assert(flag & Validator::DIGIT);
    } else {
      assert(flag & Validator::SYMBOL);
    }
  }
  return s;
}

string readLine(int a, int b) {
  string s = validator.readLine();
  assert(a <= (int)s.size() && (int)s.size() <= b);
  return s;
}
  
void readSpace() {
  assert(validator.readChar() == ' ');
}
  
void readEoln() {
  assert(validator.readChar() == '\n');
}
