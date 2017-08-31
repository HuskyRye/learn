#pragma once

template<typename Iter, class T>
bool binary_search(Iter first, Iter last, T& val)
{
    if (first == last)
        return false;
    auto middle = first+(last-first)/2;
    if (*middle == val)
        return true;
    if (middle == first)
        return false;
    if (*middle < val)
        return binary_search(middle, last, val);
    else
        return binary_search(first, middle, val);
}