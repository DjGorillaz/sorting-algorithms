#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>

#include <is_ra_iter.h>

template <typename Iter>
typename std::enable_if<IsRAIter_v<Iter>>::type bubble_sort(Iter first, Iter last)
{
    auto size = std::distance(first, last);
    for (int i = 0; i < size; ++i)
    {
        --last;
        for(auto curr = first; curr != last; ++curr)
        {
            auto next = std::next(curr);
            if (*curr > *next)
                std::iter_swap(curr, next);
        }
    }
}