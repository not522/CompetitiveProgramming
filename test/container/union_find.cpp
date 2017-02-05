#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "container/union_find.hpp"

BOOST_AUTO_TEST_SUITE(UNION_FIND)
BOOST_AUTO_TEST_CASE(HAND) {
  UnionFind uf(10);
  BOOST_CHECK(uf.equal(0, 0));
  BOOST_CHECK(!uf.equal(0, 1));
  BOOST_CHECK_EQUAL(uf.size(), 10);
  BOOST_CHECK_EQUAL(uf.size(0), 1);
  uf.unite(0, 1);
  BOOST_CHECK(uf.equal(0, 1));
  BOOST_CHECK_EQUAL(uf.size(), 9);
  BOOST_CHECK_EQUAL(uf.size(0), 2);
  uf.unite(0, 2);
  uf.unite(1, 2);
  BOOST_CHECK(uf.equal(0, 2));
  BOOST_CHECK_EQUAL(uf.size(), 8);
  BOOST_CHECK_EQUAL(uf.size(0), 3);
  for (int i = 0; i < 10; ++i) {
    BOOST_CHECK_EQUAL(uf.find(i) == i, uf.isRoot(i));
  }
  auto groups = uf.groups();
  vector<vector<int>> g{{0, 1, 2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}};
  BOOST_CHECK_EQUAL(groups.size(), g.size());
  for (uint i = 0; i < groups.size(); ++i) {
    BOOST_CHECK_EQUAL_COLLECTIONS(groups[i].begin(), groups[i].end(), g[i].begin(), g[i].end());
  }
}
BOOST_AUTO_TEST_SUITE_END()
