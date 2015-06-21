#include "geometry/real.hpp"

class Point {
public:
  Real x, y;
  
  Point() {}

  Point (Real x, Real y) : x(x), y(y) {}
  
  Point operator+=(const Point& p) {
    x += p.x;
    y += p.y;
    return *this;
  }

  Point operator-=(const Point& p) {
    x -= p.x;
    y -= p.y;
    return *this;
  }

  Point operator*=(const Point& p) {
    x *= p.x;
    y *= p.y;
    return *this;
  }

  Point operator/=(const Point& p) {
    x /= p.x;
    y /= p.y;
    return *this;
  }
	
	Point operator+(const Point& m) const {
		Point res = *this;
		res += m;
		return res;
	}
	
	Point operator-(const Point& m) const {
		Point res = *this;
		res -= m;
		return res;
	}
	
	Point operator*(const Point& m) const {
		Point res = *this;
		res *= m;
		return res;
	}
	
	Point operator/(const Point& m) const {
		Point res = *this;
		res /= m;
		return res;
	}
};

ostream& operator<<(ostream& os, Point a) {
	os << "(" << a.x << "," << a.y << ")";
	return os;
}

istream& operator>>(istream& is, Point& a) {
  Real x, y;
	is >> x >> y;
	a = Point(x, y);
	return is;
}
