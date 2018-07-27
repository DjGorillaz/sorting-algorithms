#include <array>
#include <algorithm>
#include <functional>
#include <iterator>
#include <deque>

#include "gtest/gtest.h"
#include "sortings.h"

namespace {
  // The fixture for testing class Foo.
  template <typename Container>
  class TestSort : public ::testing::Test {
  protected:

    typedef typename Container::iterator Iter;
  
    // You can remove any or all of the following functions if its body
    // is empty.
/*
    TestSort() = default;

    ~TestSort() override = default;
    */

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
      // Code here will be called immediately after the constructor (right
      // before each test).
      functions.emplace_back(&bubble_sort<Iter>);
      functions.emplace_back(&insertion_sort<Iter>);
      functions.emplace_back(&gnome_sort<Iter>);
    }

    void TearDown() override {
      // Code here will be called immediately after each test (right
      // before the destructor).
    }

    void SortArray(Iter first, Iter last, std::function<void(Iter, Iter)> sorting_func)
    {
      sorting_func(first, last);
    }

    std::vector<std::function<void(Iter, Iter)>> functions;

    // std::vector<std::function<void(std::vector<int>::iterator, std::vector<int>::iterator)>> functions;  
    // Objects declared here can be used by all tests in the test case for Foo.
  };


// Tests that SetUpTestCase()/TearDownTestCase(), fixture ctor/dtor,
// and SetUp()/TearDown() work correctly in typed tests

typedef testing::Types<std::vector<int>,
                       //std::vector<float>,
                       //std::vector<double>,
                       std::deque<int>
                       /*std::array<int, 1000>*/ > MyTypes;
  TYPED_TEST_CASE(TestSort, MyTypes);
  
  TYPED_TEST(TestSort, EmptyArray)
  {
    TypeParam empty_container;
    for (auto& func: /* this-> */ functions)
      {
        SortArray(empty_container.begin(), empty_container.end(), func);
        ASSERT_TRUE(std::is_sorted(empty_container.begin(), empty_container.end()));
      }
  }

  TYPED_TEST(TestSort, OneElement)
  {
    TypeParam container;
    container.emplace_back(0);
    for (auto& func: /* this-> */ functions)
      {
        SortArray(container.begin(), container.end(), func);
        ASSERT_TRUE(std::is_sorted(container.begin(), container.end()));
      }
  }

  TYPED_TEST(TestSort, RepeatedElements)
  {
    TypeParam container = {0, 0, 0};
    for (auto& func: /* this-> */ functions)
      {
        SortArray(container.begin(), container.end(), func);
        ASSERT_TRUE(std::is_sorted(container.begin(), container.end()));
      }
  }

  TYPED_TEST(TestSort, MaxMinInt)
  {
    TypeParam container;
    container.emplace_back(INT_MAX);
    container.emplace_back(INT_MIN);
    container.emplace_back(0);
    for (auto& func: /* this-> */ functions)
      {
        SortArray(container.begin(), container.end(), func);
        ASSERT_TRUE(std::is_sorted(container.begin(), container.end()));
      }
  }

  TYPED_TEST(TestSort, AllPermutations)
  {
    TypeParam container = {-11, -3, 0, 42, 42, 42, 1000};
    do
    {
      for (auto& func: functions)
      {
        TypeParam container_copy {container};
        typedef TypeParam::iterator iter_type;
        //typename std::iterator_traits<Iter>::iterator_category
        //<std::iterator_traits<typename decltype(container_copy)::iterator>::iterator_category>
        SortArray(container_copy.begin(), container_copy.end(), func);
        ASSERT_TRUE(std::is_sorted(container_copy.begin(), container_copy.end()));
      }
    }
    while(std::next_permutation(container.begin(), container.end()));
  }

//Random test(several cycles),
//Large container test
}  
