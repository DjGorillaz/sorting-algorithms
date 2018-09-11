#pragma once

#include <iterator>

#include <is_ra_iter.h>

template <typename Iter>
typename std::enable_if<IsRAIter_v<Iter>>::type gnome_sort(Iter first, Iter last)
{
    if (first == last) return;
    for(auto outer = std::next(first); outer != last; ++outer)
    {
        for (auto inner = outer; inner != first; --inner)
        {
            auto inner_prev = std::prev(inner);
            if (*inner < *inner_prev)
                std::iter_swap(inner, inner_prev);
            else
                break;
        }   
    }
}