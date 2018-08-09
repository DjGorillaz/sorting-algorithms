#pragma once

#include <iterator>

#include <is_ra_iter.h>

template <typename Iter>
typename std::enable_if<IsRAIter_v<Iter>>::type cocktail_shaker_sort(Iter first, Iter last)
{
    if (first == last) return;

    --last;
    while (first < last)
    {
        for (auto curr = first; curr != last; ++curr)
        {
            auto next_curr = std::next(curr);
            if (*curr > *next_curr)
                std::iter_swap(curr, next_curr);
        }
        --last;

        for (auto curr = last; curr != first; --curr)
        {
            auto prev_curr = std::prev(curr);
            if (*curr < *prev_curr)
                std::iter_swap(curr, prev_curr);
        }
        ++first;
    }
}