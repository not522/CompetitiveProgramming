#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "math/fraction.hpp"

BOOST_AUTO_TEST_SUITE(FRACTION)
BOOST_AUTO_TEST_CASE(HAND) {
  Fraction<int> a(10), b(20, 30), r;
  r = Fraction<int>(32, 3);
  BOOST_CHECK_EQUAL(a + b, r);
  r = Fraction<int>(28, 3);
  BOOST_CHECK_EQUAL(a - b, r);
  r = Fraction<int>(20, 3);
  BOOST_CHECK_EQUAL(a * b, r);
  r = Fraction<int>(15);
  BOOST_CHECK_EQUAL(a / b, r);
}
BOOST_AUTO_TEST_SUITE_END()
