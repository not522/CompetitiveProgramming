#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <experimental/random>

#include "vector.hpp"
#include "container/skew_heap.hpp"

BOOST_AUTO_TEST_SUITE(SKEW_HEAP)
BOOST_AUTO_TEST_CASE(HAND) {
  SkewHeap<int> heap1, heap2;
  BOOST_CHECK(heap1.empty());
  heap1.emplace(1);
  BOOST_CHECK(!heap1.empty());
  BOOST_CHECK_EQUAL(heap1.top(), 1);
  heap1.emplace(0);
  BOOST_CHECK_EQUAL(heap1.top(), 0);
  heap1.pop();
  BOOST_CHECK_EQUAL(heap1.top(), 1);
  heap2.emplace(0);
  heap1 += heap2;
  BOOST_CHECK_EQUAL(heap1.top(), 0);
  heap1.clear();
  BOOST_CHECK(heap1.empty());
}

BOOST_AUTO_TEST_CASE(INCREASE) {
  constexpr int SIZE = 1e3;
  SkewHeap<int> heap1;
  for (int i = 0; i < SIZE; ++i) {
    SkewHeap<int> heap2;
    heap2.emplace(i);
    heap1 += heap2;
    BOOST_CHECK(!heap1.empty());
    BOOST_CHECK_EQUAL(heap1.top(), 0);
    BOOST_CHECK_EQUAL(heap1.size(), i + 1);
  }
  for (int i = 0; i < SIZE; ++i) {
    BOOST_CHECK(!heap1.empty());
    BOOST_CHECK_EQUAL(heap1.top(), i);
    BOOST_CHECK_EQUAL(heap1.size(), SIZE - i);
    heap1.pop();
  }
  BOOST_CHECK(heap1.empty());
  BOOST_CHECK_EQUAL(heap1.size(), 0);
}

BOOST_AUTO_TEST_CASE(INCREASE_LARGE, *boost::unit_test::timeout(1)) {
  constexpr int SIZE = 1e5;
  SkewHeap<int> heap1;
  for (int i = 0; i < SIZE; ++i) {
    SkewHeap<int> heap2;
    heap2.emplace(i);
    heap1 += heap2;
  }
  for (int i = 0; i < SIZE; ++i) heap1.pop();
}

BOOST_AUTO_TEST_CASE(DECREASE) {
  constexpr int SIZE = 1e3;
  SkewHeap<int> heap1;
  for (int i = SIZE - 1; i >= 0; --i) {
    SkewHeap<int> heap2;
    heap2.emplace(i);
    heap1 += heap2;
    BOOST_CHECK(!heap1.empty());
    BOOST_CHECK_EQUAL(heap1.top(), i);
    BOOST_CHECK_EQUAL(heap1.size(), SIZE - i);
  }
  for (int i = 0; i < SIZE; ++i) {
    BOOST_CHECK(!heap1.empty());
    BOOST_CHECK_EQUAL(heap1.top(), i);
    BOOST_CHECK_EQUAL(heap1.size(), SIZE - i);
    heap1.pop();
  }
  BOOST_CHECK(heap1.empty());
  BOOST_CHECK_EQUAL(heap1.size(), 0);
}

BOOST_AUTO_TEST_CASE(DECREASE_LARGE, *boost::unit_test::timeout(1)) {
  constexpr int SIZE = 1e5;
  SkewHeap<int> heap1;
  for (int i = SIZE - 1; i >= 0; --i) {
    SkewHeap<int> heap2;
    heap2.emplace(i);
    heap1 += heap2;
  }
  for (int i = 0; i < SIZE; ++i) heap1.pop();
}

BOOST_AUTO_TEST_CASE(RANDOM) {
  constexpr int SIZE = 1e3;
  vector<SkewHeap<int>> heaps(SIZE);
  vector<priority_queue<int, vector<int>, greater<int>>> ques(SIZE);
  for (int i = 0; i < SIZE; ++i) {
    heaps[i].emplace(i);
    ques[i].emplace(i);
  }
  for (int i = 0; i < SIZE - 1; ++i) {
    int a = experimental::randint(0, int(ques.size()) - 1);
    int b = experimental::randint(0, int(ques.size()) - 2);
    if (a <= b) ++b;
    if (a == int(ques.size()) - 1) swap(a, b);
    heaps[a] += heaps[b];
    heaps[b] = move(heaps.back());
    heaps.pop_back();
    while (!ques[b].empty()) {
      ques[a].emplace(ques[b].top());
      ques[b].pop();
    }
    ques[b] = move(ques.back());
    ques.pop_back();
    BOOST_CHECK_EQUAL(heaps[a].top(), ques[a].top());
    BOOST_CHECK_EQUAL(heaps[a].size(), ques[a].size());
    if (ques[a].size() > 1u && experimental::randint(0, 1)) {
      heaps[a].pop();
      ques[a].pop();
    }
  }
  int size = ques[0].size();
  for (int i = 0; i < size; ++i) {
    BOOST_CHECK(!heaps[0].empty());
    BOOST_CHECK_EQUAL(heaps[0].top(), ques[0].top());
    BOOST_CHECK_EQUAL(heaps[0].size(), ques[0].size());
    heaps[0].pop();
    ques[0].pop();
  }
  BOOST_CHECK(heaps[0].empty());
  BOOST_CHECK_EQUAL(heaps[0].size(), 0);
}

BOOST_AUTO_TEST_CASE(RANDOM_LARGE, *boost::unit_test::timeout(1)) {
  constexpr int SIZE = 1e5;
  vector<SkewHeap<int>> heaps(SIZE);
  vector<priority_queue<int, vector<int>, greater<int>>> ques(SIZE);
  for (int i = 0; i < SIZE; ++i) {
    heaps[i].emplace(i);
    ques[i].emplace(i);
  }
  for (int i = 0; i < SIZE - 1; ++i) {
    int a = experimental::randint(0, int(ques.size()) - 1);
    int b = experimental::randint(0, int(ques.size()) - 2);
    if (a <= b) ++b;
    if (a == int(ques.size()) - 1) swap(a, b);
    heaps[a] += heaps[b];
    heaps[b] = move(heaps.back());
    heaps.pop_back();
    while (!ques[b].empty()) {
      ques[a].emplace(ques[b].top());
      ques[b].pop();
    }
    ques[b] = move(ques.back());
    ques.pop_back();
    if (ques[a].size() > 1u && experimental::randint(0, 1)) {
      heaps[a].pop();
      ques[a].pop();
    }
  }
  int size = ques[0].size();
  for (int i = 0; i < size; ++i) {
    heaps[0].pop();
    ques[0].pop();
  }
}
BOOST_AUTO_TEST_SUITE_END()
