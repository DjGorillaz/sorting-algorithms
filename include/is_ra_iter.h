#pragma once

#include <iterator>

template<typename Iter>
using IsRAIter = std::is_base_of<
                                std::random_access_iterator_tag, 
                                typename std::iterator_traits<Iter>::iterator_category
                                >;

template<typename Iter>
constexpr bool IsRAIter_v = IsRAIter<Iter>::value;