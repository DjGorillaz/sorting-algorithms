#include <array>
#include <algorithm>
#include <functional>
#include <iterator>
#include <deque>
#include <limits>
#include <list>

#include "gtest/gtest.h"
#include "sortings.h"

namespace {
  template <typename Container>
  class TestSort : public ::testing::Test {
  protected:

    typedef typename Container::iterator Iter;
  
    void SetUp() override {
      functions.emplace_back(&bubble_sort<Iter>);
      functions.emplace_back(&cocktail_shaker_sort<Iter>);
      functions.emplace_back(&counting_sort<Iter>);
      functions.emplace_back(&gnome_sort<Iter>);
      functions.emplace_back(&insertion_sort<Iter>);
      functions.emplace_back(&quick_sort<Iter>);
      functions.emplace_back(&quick_sort_lomuto<Iter>);
    }

    void SortArray(Iter first, Iter last, std::function<void(Iter, Iter)> sorting_func)
    {
      sorting_func(first, last);
    }

    std::vector<std::function<void(Iter, Iter)>> functions;
  };

typedef testing::Types<std::vector<int>,
                       //std::vector<float>,
                       std::deque<long long>
                       /*std::array<int, 1000>*/ > MyTypes;
  TYPED_TEST_CASE(TestSort, MyTypes);
  
  TYPED_TEST(TestSort, EmptyContainer)
  {
    TypeParam empty_container;
    for (auto& func: functions)
      {
        SortArray(empty_container.begin(), empty_container.end(), func);
        ASSERT_TRUE(std::is_sorted(empty_container.begin(), empty_container.end()));
      }
  }

  TYPED_TEST(TestSort, OneElement)
  {
    TypeParam container;
    container.emplace_back(0);
    for (auto& func: functions)
      {
        SortArray(container.begin(), container.end(), func);
        ASSERT_TRUE(std::is_sorted(container.begin(), container.end()));
      }
  }

  TYPED_TEST(TestSort, RepeatedElements)
  {
    TypeParam container = {0, 0, 0};
    for (auto& func: functions)
      {
        SortArray(container.begin(), container.end(), func);
        ASSERT_TRUE(std::is_sorted(container.begin(), container.end()));
      }
  }

  TYPED_TEST(TestSort, MaxMin)
  {
    TypeParam container = {0,
                           std::numeric_limits<TypeParam::iterator::value_type>::max(),
                           std::numeric_limits<TypeParam::iterator::value_type>::min()};
    for (auto& func: functions)
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
        SortArray(container_copy.begin(), container_copy.end(), func);
        ASSERT_TRUE(std::is_sorted(container_copy.begin(), container_copy.end()));
      }
    }
    while(std::next_permutation(container.begin(), container.end()));
  }
}  
