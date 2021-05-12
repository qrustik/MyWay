#pragma once
#include "mergesort.hpp"
#include "detail.hpp"

namespace myalgo
{
    template <typename T>
    void quickSort(T a[], size_t l, size_t r) {
        if (r - l < 11) {
            mergeSort<T>(a, l, r);
            return;
        }

        detail::swap(a[detail::median<T>(a, l, r)], a[(r + l) / 2]);

        size_t i = detail::partition(a, l, r);

        quickSort(a, l, i);
        quickSort(a, i + 1, r);
    }
}