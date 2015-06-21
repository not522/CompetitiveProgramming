#include "inverse.hpp"

class Mint {
private:
  static long long mod;
  static Inverse inverse;
  long long val;
	
public:
	Mint() {}

	Mint(const long long& val) {
    this->val = val % mod;
    if (this->val < 0) this->val += mod;
  }

  static void setMod(const long long& m) {
    mod = m;
    inverse = Inverse(m);
  }
	
	Mint operator+=(const Mint& m) {
		val += m.val;
		if (val >= mod) val -= mod;
		return *this;
	}
  
	Mint operator-=(const Mint& m) {
		val -= m.val;
		if (val < 0) val += mod;
		return *this;
	}
  
	Mint operator*=(const Mint& m) {
		val *= m.val;
		val %= mod;
		return *this;
	}
  
	Mint operator/=(const Mint& m) {
		val *= inverse(m.val);
		val %= mod;
		return *this;
	}
	
	Mint operator+(const Mint& m) const {
		Mint res = *this;
		res += m;
		return res;
	}
	
	Mint operator-(const Mint& m) const {
		Mint res = *this;
		res -= m;
		return res;
	}
	
	Mint operator*(const Mint& m) const {
		Mint res = *this;
		res *= m;
		return res;
	}
	
	Mint operator/(const Mint& m) const {
		Mint res = *this;
		res /= m;
		return res;
	}
	
	Mint operator++() {return val += 1;}
	
	operator long long() {
		return val;
	}
};

Mint pow(const Mint& m, long long n) {
  if (n == 0) {
    return 1;
  } else if (n < 0) {
    return pow(m, -n);
  }
  Mint mm = pow(m, n / 2);
  mm *= mm;
  if (n % 2) mm *= m;
  return mm;
}

long long Mint::mod = 1000000007;
Inverse Mint::inverse(1000000007);

ostream& operator<<(ostream& os, Mint a) {
	os << (long long)a;
	return os;
}

istream& operator>>(istream& is, Mint& a) {
	long long n;
	is >> n;
	a = n;
	return is;
}
