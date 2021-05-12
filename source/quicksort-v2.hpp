#pragma once
#include "insertionsort.hpp"
#include "detail.hpp"
#include "bisearch.hpp"

namespace myalgo
{
    //Determined version of quick sort

    template <typename T>
    void quickSort_2(T a[], const size_t& left, const size_t& right) {
        if (right - left < 11) {
            insertionSort(a, left, right);
            return;
        }
        T med = detail::median(a, left, right);
        size_t index = biSearch(a, left, right, med);

        swap(a[med], a[(left + right) / 2]);

        size_t pivot = detail::partition(a, left, right);
        quickSort_2(a, left, pivot);
        quickSort_2(a, pivot + 1, right);
    }
}

