#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "count.hpp"

BOOST_AUTO_TEST_SUITE(COUNT)
BOOST_AUTO_TEST_CASE(VECTOR_HAND) {
  vector<int> v{3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  auto m = count(v);
  map<int, int> p{{1, 2}, {2, 1}, {3, 2}, {4, 1}, {5, 2}, {6, 1}, {9, 1}};
  BOOST_CHECK_EQUAL(m.size(), p.size());
  BOOST_CHECK(equal(m.begin(), m.end(), p.begin()));
}

BOOST_AUTO_TEST_CASE(STRING_HAND) {
  string v = "3.141592653";
  auto m = count(v);
  map<char, int> p{{'1', 2}, {'2', 1}, {'3', 2}, {'4', 1}, {'5', 2}, {'6', 1}, {'9', 1}, {'.', 1}};
  BOOST_CHECK_EQUAL(m.size(), p.size());
  BOOST_CHECK(equal(m.begin(), m.end(), p.begin()));
}
BOOST_AUTO_TEST_SUITE_END()
