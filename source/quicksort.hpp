#pragma once
#include "insertionsort.hpp"
#include "detail.hpp"

namespace myalgo
{
    template <typename T>
    void quickSort(T a[], size_t l, size_t r) {
        if (r - l < 11) {
            insertionSort(a, l, r);
            return;
        }

        size_t pivot = detail::partition(a, l, r);
        quickSort(a, l, pivot);
        quickSort(a, pivot + 1, r);
    }
}