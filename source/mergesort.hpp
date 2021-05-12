#pragma once
#include "detail.hpp"
namespace myalgo
{
    template <typename T>
    static void mergeSort(T a[], const size_t& left, const size_t& right) {
        T _buf[right - left + 1] = {};
        detail::_mergesort<T>(a, left, right, _buf);
    }
};