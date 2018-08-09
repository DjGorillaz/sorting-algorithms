#pragma once

#include <iterator>
#include <vector>
#include <map>

#include <is_ra_iter.h>

template <typename Iter>
typename std::enable_if<IsRAIter_v<Iter>>::type counting_sort(Iter first, Iter last)
{
    std::map<Iter::value_type, long long> map;
    auto curr = first;
    for (; curr != last; ++curr)
    {
        //emplace 1 or increment value
        auto [pair, result] = map.emplace(*curr, 1);
        if ( ! result)
            ++(pair->second);
    }
    
    curr = first;
    for (auto& pair: map)
    {
        while (pair.second > 0)
        {
            *curr = pair.first;
            --pair.second;
            ++curr;
        }
    }
}

template <typename Iter>
typename std::enable_if<IsRAIter_v<Iter>>::type counting_sort_vector(Iter first, Iter last)
{
    if (first == last) return;

    auto [min, max] = std::minmax_element(first, last);
    //size must be less than std::numeric_limits<Iter::value_type>
    std::size_t size = *max - *min + 1;
    std::vector<Iter::value_type> vector(size, 0);

    auto abs_min = *min * (-1);

    auto curr = first;
    for (; curr != last; ++curr)
    {
        auto& value = vector[*curr + abs_min];
        if (value == 0) 
            value = 1;
        else
            ++value;
    }
    
    curr = first;
    for (std::size_t i = 0; i < size; ++i)
    {
        auto& value = vector[i];
        while (value > 0)
        {
            *curr = i - abs_min;
            --value;
            ++curr;
        }
    }
}