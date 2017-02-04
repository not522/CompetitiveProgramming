#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "cumulative_sum_1D.hpp"

BOOST_AUTO_TEST_SUITE(CUMULATIVE_SUM_1D)
BOOST_AUTO_TEST_CASE(HAND) {
  vector<int> v{3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  CumulativeSum1D<int> c(v);
  BOOST_CHECK_EQUAL(c.value(0), 3);
  BOOST_CHECK_EQUAL(c.value(5), 9);
  BOOST_CHECK_EQUAL(c.sum(0, 10), 39);
  BOOST_CHECK_EQUAL(c.sum(3, 7), 17);
}

BOOST_AUTO_TEST_CASE(ADD_HAND) {
  CumulativeSum1D<int> c(10);
  c.add(0, 10, 1);
  c.add(0, 2);
  c.add(2, 3);
  c.add(4, 10, 1);
  c.add(4, 6, 3);
  c.add(5, 4);
  c.add(7, 10, 1);
  c.add(7, 9, 2);
  c.add(7, 1);
  BOOST_CHECK_EQUAL(c.value(0), 3);
  BOOST_CHECK_EQUAL(c.value(5), 9);
  BOOST_CHECK_EQUAL(c.sum(0, 10), 39);
  BOOST_CHECK_EQUAL(c.sum(3, 7), 17);
}
BOOST_AUTO_TEST_SUITE_END()
