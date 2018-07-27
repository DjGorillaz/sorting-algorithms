#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>

#include <is_ra_iter.h>

template <typename Iter>
typename std::enable_if<IsRAIter_v<Iter>>::type insertion_sort(Iter first, Iter last)
{
    if (first == last) return;
    for(auto outer = std::next(first); outer != last; ++outer)
    {
        auto value = *outer;
        auto inner = outer;
        for (inner; inner != first; --inner)
        {
            auto inner_prev = std::prev(inner);
            if (value < *inner_prev)
            {
                *inner = std::move(*inner_prev); // *inner = *inner_prev;
            }
            else
                break;
        }
        *inner = value;    
    }
}