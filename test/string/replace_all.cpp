#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "string/replace_all.hpp"

BOOST_AUTO_TEST_SUITE(REPLACE_ALL)
BOOST_AUTO_TEST_CASE(HAND) {
  string a = "abcabcabc";
  replaceAll(a, "ab", "a");
  BOOST_CHECK_EQUAL(a, "acacac");
  string b = "abbabbabb";
  replaceAll(b, "ab", "a");
  BOOST_CHECK_EQUAL(b, "ababab");
  string c = "abbabbabb";
  replaceAll<true>(c, "ab", "a");
  BOOST_CHECK_EQUAL(c, "aaa");
  string d = "ab ab ab";
  replaceAll<true>(d, "ab", "xyz");
  BOOST_CHECK_EQUAL(d, "xyz xyz xyz");
}
BOOST_AUTO_TEST_SUITE_END()
