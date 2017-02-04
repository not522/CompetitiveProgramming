#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "minmax.hpp"

BOOST_AUTO_TEST_SUITE(MINMAX)
BOOST_AUTO_TEST_CASE(HAND) {
  int a = 1;
  chmin(a, 2);
  BOOST_CHECK_EQUAL(a, 1);
  chmin(a, 0);
  BOOST_CHECK_EQUAL(a, 0);
  chmax(a, 2);
  BOOST_CHECK_EQUAL(a, 2);
  chmax(a, 0);
  BOOST_CHECK_EQUAL(a, 2);
}
BOOST_AUTO_TEST_SUITE_END()
