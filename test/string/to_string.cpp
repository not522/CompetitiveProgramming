#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "string/to_string.hpp"

BOOST_AUTO_TEST_SUITE(TO_STRING)
BOOST_AUTO_TEST_CASE(HAND) {
  BOOST_CHECK_EQUAL(to_string(vector<int>{1, 2, 3}), "1 2 3");
  BOOST_CHECK_EQUAL(to_string(vector<vector<int>>(3, vector<int>{1, 2, 3})), "1 2 3 1 2 3 1 2 3");
}
BOOST_AUTO_TEST_SUITE_END()
