#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "string/join.hpp"

BOOST_AUTO_TEST_SUITE(JOIN)
BOOST_AUTO_TEST_CASE(HAND) {
  vector<int> v{3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  BOOST_CHECK_EQUAL(join(v), "3 1 4 1 5 9 2 6 5 3");
  BOOST_CHECK_EQUAL(join(v, ','), "3,1,4,1,5,9,2,6,5,3");
}
BOOST_AUTO_TEST_SUITE_END()
