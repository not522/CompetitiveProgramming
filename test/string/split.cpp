#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "string/split.hpp"

BOOST_AUTO_TEST_SUITE(SPLIT)
BOOST_AUTO_TEST_CASE(HAND) {
  vector<string> res(3, "abc");
  auto a = split("abc abc abc");
  BOOST_CHECK_EQUAL_COLLECTIONS(a.begin(), a.end(), res.begin(), res.end());
  auto b = split("abc,abc,abc", ',');
  BOOST_CHECK_EQUAL_COLLECTIONS(b.begin(), b.end(), res.begin(), res.end());
  auto c = split("abc  abc  abc");
  BOOST_CHECK_EQUAL_COLLECTIONS(c.begin(), c.end(), res.begin(), res.end());
  auto d = split(" abc abc abc ");
  BOOST_CHECK_EQUAL_COLLECTIONS(d.begin(), d.end(), res.begin(), res.end());
}
BOOST_AUTO_TEST_SUITE_END()
