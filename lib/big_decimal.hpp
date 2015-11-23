#pragma once
#include "arithmetic.hpp"
#include "ordered.hpp"

template<int IntegerSize = 6, int DecimalSize = 9>
class BigDecimal : public Arithmetic<BigDecimal<IntegerSize, DecimalSize>>, public Ordered<BigDecimal<IntegerSize, DecimalSize>> {
 private:
  const static int BitSize = 31;
  const static bool PLUS = false;
  const static bool MINUS = true;

  constexpr static long double EPSILON = pow<long double>(2, -(BitSize - 4) * DecimalSize);

  bool sign;
  array<long long, IntegerSize + DecimalSize> d;

 public:
  BigDecimal() {
    *this = BigDecimal(0);
  }

  BigDecimal(int n) {
    sign = PLUS;
    for (auto& i : d) i = 0;
    d[DecimalSize] = n;
    normal();
  }

  BigDecimal(long long n) {
    sign = PLUS;
    for (auto& i : d) i = 0;
    d[DecimalSize] = n;
    normal();
  }

  BigDecimal(string str) {
    *this = BigDecimal(0);
    bool minus = false;
    if (str[0] == '-') {
      minus = true;
      str = str.substr(1);
    }
    BigDecimal t = 1;
    bool decimal = false;
    for (int i = 0; i < (int)str.size(); ++i) {
      if (str[i] == '.') {
        decimal = true;
      } else {
        if (decimal) *this += (t /= 10) * (str[i] - '0');
        else *this = *this * 10 + (str[i] - '0');
      }
    }
    if (minus) sign = MINUS;
  }

  BigDecimal(double r) {
    *this = BigDecimal(0);
    int n;
    BigDecimal b = (r >= 0 ? BigDecimal(1) : BigDecimal(-1));
    r = 2 * abs(frexp(abs(r), &n));
    b <<= n - 1;
    while (r) {
      if (r >= 1) {
        *this += b;
        r -= 1;
      }
      r *= 2;
      b >>= 1;
    }
  }

  BigDecimal(long double r) {
    *this = BigDecimal(0);
    int n;
    BigDecimal b = (r >= 0 ? BigDecimal(1) : BigDecimal(-1));
    r = 2 * abs(frexp(abs(r), &n));
    b <<= n - 1;
    while (r) {
      if (r >= 1) {
        *this += b;
        r -= 1;
      }
      r *= 2;
      b >>= 1;
    }
  }

  BigDecimal normal() {
    for (int i = 0; i < IntegerSize + DecimalSize - 1; ++i) {
      d[i + 1] += d[i] >> BitSize;
      d[i] &= (1ll << BitSize) - 1;
    }
    if (d[IntegerSize + DecimalSize - 1] < 0) {
      sign = !sign;
      for (auto& i : d) i = -i;
      normal();
    }
    if (d.back() >= (1ll << BitSize)) throw "overflow";
    if (all_of(d.begin(), d.end(), [](long long i){return i == 0;})) sign = PLUS;
    return *this;
  }

  BigDecimal operator-() const {
    BigDecimal bd(*this);
    bd.sign = !bd.sign;
    return bd;
  }

  BigDecimal operator<<(int a) const {return BigDecimal(*this) <<= a;}
  BigDecimal operator>>(int a) const {return BigDecimal(*this) >>= a;}
  BigDecimal operator%(const BigDecimal &a) const {return BigDecimal(*this) %= a;}

  BigDecimal operator<<=(int a) {
    if (a < 0) return *this >>= -a;
    while (a >= BitSize) {
      if (d.back()) throw "overflow";
      for (int i = IntegerSize + DecimalSize; --i > 0; ) d[i] = d[i - 1];
      d[0] = 0;
      a -= BitSize;
    }
    if (d.back() >= (1ll << (BitSize - a))) throw "overflow";
    for (auto& i : d) i <<= a;
    return normal();
  }

  BigDecimal operator>>=(int a) {
    if (a < 0) return *this <<= -a;
    while (a >= BitSize) {
      for (int i = 0; i < IntegerSize + DecimalSize - 1; ++i) d[i] = d[i + 1];
      d.back() >>= BitSize;
      a -= BitSize;
    }
    for (int i = 0; i < IntegerSize + DecimalSize - 1; ++i) {
      d[i] |= d[i + 1] << BitSize;
      d[i + 1] = 0;
    }
    for (auto& i : d) i >>= a;
    return normal();
  }

  BigDecimal operator+=(const BigDecimal &a) {
    if (sign == a.sign) for (int i = 0; i < IntegerSize + DecimalSize; ++i) d[i] += a.d[i];
    else for (int i = 0; i < IntegerSize + DecimalSize; ++i) d[i] -= a.d[i];
    return normal();
  }

  BigDecimal operator-=(const BigDecimal &a) {
    return *this += -a;
  }

  BigDecimal operator*=(const BigDecimal& a) {
    BigDecimal res = 0;
    for (int i = 0; i < IntegerSize + DecimalSize; ++i) {
      if (i < DecimalSize) res = (res + *this * a.d[i]) >> BitSize;
      else res += *this * a.d[i] << (i - DecimalSize) * BitSize;
    }
    res.sign = (sign == a.sign ? PLUS : MINUS);
    return *this = res.normal();
  }

  BigDecimal operator*=(const unsigned int& a) {
    for (auto& i : d) i *= a;
    return this->normal();
  }

  BigDecimal operator/=(const BigDecimal &a) {
    if (a == 0) throw "divide by zero";
    BigDecimal rev = (double)1 / a.toDouble();
    for (int i = 0; i < 7; ++i) rev = (rev << 1) - a * rev * rev;
    rev.sign = a.sign;
    return *this *= rev;
  }

  BigDecimal operator%=(const BigDecimal &a) {
    if (a == 0) throw "modulo by zero";
    return *this -= floor(*this / a) * a;
  }

  BigDecimal operator-(const BigDecimal& v) const {
    return BigDecimal(*this) -= v;
  }

  BigDecimal operator++() {
    return *this += 1;
  }

  BigDecimal operator++(int) {
    BigDecimal bd = *this;
    *this += 1;
    return bd;
  }

  BigDecimal operator--() {
    return *this -= 1;
  }

  BigDecimal operator--(int) {
    BigDecimal bd = *this;
    *this -= 1;
    return bd;
  }

  bool operator<(const BigDecimal &a) const {
    BigDecimal aa = a - EPSILON;
    if (sign == MINUS) {
      if (aa.sign == MINUS) {
        if (a.sign == MINUS) return -a < -*this;
        else return *this + EPSILON < a + EPSILON;
      } else {
        return true;
      }
    }
    if (aa.sign == MINUS) return false;
    for (int i = IntegerSize + DecimalSize; i-- > 0; ) if (d[i] != aa.d[i]) return d[i] < aa.d[i];
    return false;
  }

  bool equals(const BigDecimal &a) const {
    return sign == a.sign && d == a.d;
  }

  int toInt() const {
    int res = 0;
    for (int i = 0; i < IntegerSize; ++i) res += d[DecimalSize + i] << BitSize * i;
    if (sign == MINUS) return -res;
    return res;
  }

  long long toLongLong() const {
    long long res = 0;
    for (int i = 0; i < IntegerSize; ++i) res += d[DecimalSize + i] << BitSize * i;
    if (sign == MINUS) return -res;
    return res;
  }

  string toString(int digit = 100, string mode = "near") const {
    string str;
    BigDecimal a = *this, bd = 1;
    if (a.sign == MINUS) {
      str += "-";
      a.sign = PLUS;
    }
    if (mode == "near") {
      BigDecimal round = BigDecimal(0.5);
      for (int i = 0; i < digit; ++i) round /= 10;
      a += round + EPSILON;
    }
    if (mode == "ceil") {
      BigDecimal round = 1;
      for (int i = 0; i < digit; ++i) round /= 10;
      a += round - EPSILON;
    }
    for (; bd <= a; bd *= 10) ++digit;
    if (bd > 1) {
      bd /= 10;
      --digit;
    }
    for (int i = 0; i < digit + 1; ++i) {
      if (bd == 0) {
        str += "0";
        continue;
      }
      if (bd * 10 == 1) str += ".";
      int d = 0;
      while (bd < a) {
        a -= bd;
        ++d;
      }
      if (d > 9) {
        d -= 10;
        string::iterator itr = str.end();
        while (true) {
          if (itr == str.begin()) {
            str = "1" + str;
            break;
          }
          --itr;
          if (*itr == '.') continue;
          ++*itr;
          if (*itr > '9') *itr = '0';
          else break;
        }
      }
      str += '0' + d;
      bd /= 10;
    }
    return str;
  }

  double toDouble() const {
    double res = 0;
    for (int i = 0; i < IntegerSize + DecimalSize; ++i) res += d[i] * pow(2, (i - DecimalSize) * BitSize);
    if (sign == MINUS) return -res;
    return res;
  }

  bool isPlus() const {
    return sign == PLUS;
  }

  bool isMinus() const {
    return sign == MINUS;
  }

  template<int I, int D>
    friend BigDecimal<I, D> pow(const BigDecimal<I, D> &x, const BigDecimal<I, D> &y);
  template<int I, int D>
    friend BigDecimal<I, D> floor(BigDecimal<I, D> x);
};

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> pi() {
  const static BigDecimal<IntegerSize, DecimalSize> PI = (atan(BigDecimal<IntegerSize, DecimalSize>(1) / 5) << 4) - (atan(BigDecimal<IntegerSize, DecimalSize>(1) / 239) << 2);
  return PI;
}

template<int IntegerSize, int DecimalSize>
inline BigDecimal<IntegerSize, DecimalSize> operator+(const int& a, BigDecimal<IntegerSize, DecimalSize> b) {
  return BigDecimal<IntegerSize, DecimalSize>(a) + b;
}

template<int IntegerSize, int DecimalSize>
inline BigDecimal<IntegerSize, DecimalSize> operator-(const int& a, BigDecimal<IntegerSize, DecimalSize> b) {
  return BigDecimal<IntegerSize, DecimalSize>(a) - b;
}

template<int IntegerSize, int DecimalSize>
inline BigDecimal<IntegerSize, DecimalSize> operator*(const int& a, BigDecimal<IntegerSize, DecimalSize> b) {
  return BigDecimal<IntegerSize, DecimalSize>(a) * b;
}

template<int IntegerSize, int DecimalSize>
inline BigDecimal<IntegerSize, DecimalSize> operator/(const int& a, BigDecimal<IntegerSize, DecimalSize> b) {
  return BigDecimal<IntegerSize, DecimalSize>(a) / b;
}

template<int IntegerSize, int DecimalSize>
ostream &operator<<(ostream &os, BigDecimal<IntegerSize, DecimalSize> a) {
  os << a.toString(os.precision());
  return os;
}

template<int IntegerSize, int DecimalSize>
istream &operator>>(istream &is, BigDecimal<IntegerSize, DecimalSize> &a) {
  string str;
  is >> str;
  a = BigDecimal<IntegerSize, DecimalSize>(str);
  return is;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> sin(BigDecimal<IntegerSize, DecimalSize> x) {
  BigDecimal<IntegerSize, DecimalSize> res = 0, xx = - x * x;
  for (int i = 1; ; i += 2) {
    x /= max(i * (i - 1), 1);
    if (x.equals(0)) break;
    res += x;
    x *= xx;
  }
  return res;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> cos(BigDecimal<IntegerSize, DecimalSize> x) {
  BigDecimal<IntegerSize, DecimalSize> res = 0, xx = - x * x;
  x = 1;
  for (int i = 0; ; i += 2) {
    x /= max(i * (i - 1), 1);
    if (x.equals(0)) break;
    res += x;
    x *= xx;
  }
  return res;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> tan(const BigDecimal<IntegerSize, DecimalSize> &x) {
  return sin(x) / cos(x);
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> asin(BigDecimal<IntegerSize, DecimalSize> x) {
  if (abs(x) > 1) throw "out of domain";
  if (x > 1 / sqrt(BigDecimal<IntegerSize, DecimalSize>(2))) return (pi<IntegerSize, DecimalSize>() >> 1) - asin(sqrt(1 - x * x));
  if (x < -1 / sqrt(BigDecimal<IntegerSize, DecimalSize>(2))) return -(pi<IntegerSize, DecimalSize>() >> 1) + asin(sqrt(1 - x * x));
  BigDecimal<IntegerSize, DecimalSize> res = 0, xx = x * x >> 2;
  for (int i = 0; ; ++i) {
    x *= max(i * 2 * (i * 2 - 1), 1);
    x /= max(i * i, 1);
    auto add = x / (i * 2 + 1);
    if (add.equals(0)) break;
    res += add;
    x *= xx;
  }
  return res;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> acos(const BigDecimal<IntegerSize, DecimalSize> &x) {
  return (pi<IntegerSize, DecimalSize>() >> 1) - asin(x);
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> atan(BigDecimal<IntegerSize, DecimalSize> x) {
  if (x.isMinus()) return -atan(-x);
  if (abs(x) > sqrt(2) + 1) return (pi<IntegerSize, DecimalSize>() >> 1) - atan(1 / x);
  if (abs(x) > sqrt(2) - 1) return (pi<IntegerSize, DecimalSize>() >> 2) + atan((x - 1) / (x + 1));
  BigDecimal<IntegerSize, DecimalSize> res = 0, xx = - x * x;
  for (int i = 1; ; i += 2) {
    auto add = x / i;
    if (add.equals(0)) break;
    res += add;
    x *= xx;
  }
  return res;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> atan2(const BigDecimal<IntegerSize, DecimalSize> &y, const BigDecimal<IntegerSize, DecimalSize> &x) {
  if (x == 0) {
    if (y > 0) return pi<IntegerSize, DecimalSize>() / 2;
    if (y < 0) return -pi<IntegerSize, DecimalSize>() / 2;
    throw "origin can't define argument";
  }
  if (x.isPlus()) return atan(y / x);
  if (y.isPlus()) return atan(y / x) + pi<IntegerSize, DecimalSize>();
  return atan(y / x) - pi<IntegerSize, DecimalSize>();
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> sinh(BigDecimal<IntegerSize, DecimalSize> x) {
  BigDecimal<IntegerSize, DecimalSize> res = 0, xx = x * x;
  for (int i = 1; ; i += 2) {
    x /= max(i * (i - 1), 1);
    if (x.equals(0)) break;
    res += x;
    x *= xx;
  }
  return res;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> cosh(BigDecimal<IntegerSize, DecimalSize> x) {
  BigDecimal<IntegerSize, DecimalSize> res = 0, xx = x * x;
  x = 1;
  for (int i = 0; ; i += 2) {
    x /= max(i * (i - 1), 1);
    if (x.equals(0)) break;
    res += x;
    x *= xx;
  }
  return res;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> tanh(const BigDecimal<IntegerSize, DecimalSize> &x) {return sinh(x) / cosh(x);}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> exp(const BigDecimal<IntegerSize, DecimalSize> &x) {
  BigDecimal<IntegerSize, DecimalSize> res = 0, xx = 1;
  for (int i = 0; ; ++i) {
    xx /= max(i, 1);
    if (xx.equals(0)) break;
    res += xx;
    xx *= x;
  }
  return res;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> log(const BigDecimal<IntegerSize, DecimalSize> &x) {
  BigDecimal<IntegerSize, DecimalSize> y = log(x.toDouble());
  BigDecimal<IntegerSize, DecimalSize> z = x / exp(y);
  BigDecimal<IntegerSize, DecimalSize> a = (z - 1) / (z + 1);
  BigDecimal<IntegerSize, DecimalSize> res = 0, b = a, aa = a * a;
  for (int i = 1; ; i += 2) {
    if (b.equals(0)) break;
    res += b / i;
    b *= aa;
  }
  return y + res * 2;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> log10(const BigDecimal<IntegerSize, DecimalSize> &x) {
  return log(x) / log(BigDecimal<IntegerSize, DecimalSize>(10));
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> pow(const BigDecimal<IntegerSize, DecimalSize> &x, const BigDecimal<IntegerSize, DecimalSize> &y) {
  if (x.isMinus()) {
    if (floor(y) == y) return floor(y).d[DecimalSize] % 2 ? -pow(-x, floor(y)) : pow(-x, floor(y));
    throw "power of negative number";
  }
  return exp(y * log(x));
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> sqrt(const BigDecimal<IntegerSize, DecimalSize> &x) {
  BigDecimal<IntegerSize, DecimalSize> r = 1 / sqrt(x.toDouble());
  for (int i = 0; i < 7; ++i) r *= (3 - x * r * r) >> 1;
  return BigDecimal<IntegerSize, DecimalSize>(1) / r;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> abs(const BigDecimal<IntegerSize, DecimalSize> &x) {
  return x.isPlus() ? x : -x;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> ceil(const BigDecimal<IntegerSize, DecimalSize> &x) {
  if (x.isMinus()) return -floor(-x);
  auto f = floor(x);
  return f == x ? f : x + 1;
}

template<int IntegerSize, int DecimalSize>
BigDecimal<IntegerSize, DecimalSize> floor(BigDecimal<IntegerSize, DecimalSize> x) {
  if (x.isMinus()) return -ceil(-x);
  x += BigDecimal<IntegerSize, DecimalSize>::EPSILON;
  for (int i = 0; i < DecimalSize; ++i) x.d[i] = 0;
  return x;
}
