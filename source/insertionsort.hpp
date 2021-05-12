#pragma once
#include "detail.hpp"

namespace myalgo
{
    template<typename T>
    void insertionSort(T a[], const size_t& size) {
        for (size_t i = 1; i < size; ++i) {
            size_t j = i;
            while (a[j] < a[j - 1]) {
                detail::swap(a[j], a[j - 1]);
                --j;
            }
        }
    }

}
