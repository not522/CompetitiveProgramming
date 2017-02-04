#pragma once
#include "template.hpp"

class EofValidator {
public:
  ~EofValidator() {assert(getchar() == EOF);}
} eofValidator;

const static int LOWER = 1;
const static int UPPER = 2;
const static int DIGIT = 4;
const static int SYMBOL = 8;

bool isSeparator(char c) {
  if (c == ' ') return true;
  if (c == '\n') return true;
  if (c == '\t') return true;
  if (c == EOF) return true;
  return false;
}

int readInt(int a, int b) {
  char c = getchar();
  int64_t n;
  if (c == '-') {
    c = getchar();
    assert('1' <= c && c <= '9');
    n = -(c - '0');
  } else {
    assert('0' <= c && c <= '9');
    n = c - '0';
  }
  if (n == 0) {
    assert(!isdigit(c = getchar()));
    ungetc(c, stdin);
    assert(a <= n && n <= b);
    return 0;
  }
  while (true) {
    c = getchar();
    if (!isdigit(c)) break;
    if (n > 0) n = n * 10 + c - '0';
    else n = n * 10 - (c - '0');
    assert(numeric_limits<int>::min() <= n && n <= numeric_limits<int>::max());
  }
  ungetc(c, stdin);
  assert(a <= n && n <= b);
  return n;
}

int64_t readLong(int64_t a, int64_t b) {
  char c = getchar();
  __int128 n;
  if (c == '-') {
    c = getchar();
    assert('1' <= c && c <= '9');
    n = -(c - '0');
  } else {
    assert('0' <= c && c <= '9');
    n = c - '0';
  }
  if (n == 0) {
    assert(!isdigit(c = getchar()));
    ungetc(c, stdin);
    assert(a <= n && n <= b);
    return 0;
  }
  while (true) {
    c = getchar();
    if (!isdigit(c)) break;
    if (n > 0) n = n * 10 + c - '0';
    else n = n * 10 - (c - '0');
    assert(numeric_limits<int64_t>::min() <= n && n <= numeric_limits<int64_t>::max());
  }
  ungetc(c, stdin);
  assert(a <= n && n <= b);
  return n;
}

string readString(int flag, size_t a, size_t b) {
  string s;
  char c;
  while (!isSeparator(c = getchar())) s += c;
  ungetc(c, stdin);
  assert(a <= s.size() && s.size() <= b);
  for (const auto& c : s) {
    assert(isgraph(c));
    if (islower(c)) assert(flag & LOWER);
    else if (isupper(c)) assert(flag & UPPER);
    else if (isdigit(c)) assert(flag & DIGIT);
    else assert(flag & SYMBOL);
  }
  return s;
}

string readLine(size_t a, size_t b) {
  string s;
  char c;
  while ((c = getchar()) != '\n') s += c;
  ungetc(c, stdin);
  assert(a <= s.size() && s.size() <= b);
  return s;
}

void readSpace() {
  assert(getchar() == ' ');
}

void readEoln() {
  assert(getchar() == '\n');
}
