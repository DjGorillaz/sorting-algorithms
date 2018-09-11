#pragma once

#include <iterator>

#include <is_ra_iter.h> 

template <typename Iter>
typename std::enable_if<IsRAIter_v<Iter>>::type quick_sort(Iter first, Iter last)
{
    if (std::distance(first, last) <= 1) return;

    //Hoare
    auto pivot = *first;
    auto left = first, right = std::prev(last);
    while(true)
    {
        while (*left < pivot)
            ++left;

        while (*right > pivot)
            --right;

        if (left >= right) break;

        std::iter_swap(left, right);
        ++left;
        --right;
    }

    quick_sort(first, std::next(right));
    quick_sort(std::next(right), last);
}

template <typename Iter>
typename std::enable_if<IsRAIter_v<Iter>>::type quick_sort_lomuto(Iter first, Iter last)
{
    //Lomuto
    if(first == last) return;
    auto pivot = std::prev(last);

    auto left = first, right = first;
    for (; right != std::prev(last); ++right)
    {
        if (*right <= *pivot)
        {
            std::iter_swap(left, right);
            ++left;
        }
    }
    std::iter_swap(left, pivot);

    quick_sort(first, left);
    quick_sort(std::next(left), last);
}