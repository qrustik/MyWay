#pragma once
#include "detail.hpp"
#include "bisearch.hpp"

// Determined version

namespace myalgo
{
    template<typename T>
    T kth_element_2(T a[], const size_t& k, const size_t& left, const size_t& right) {
        if ((right - left) == 0) {
            return a[0];
        }

        T med = detail::median(a, left, right);

        size_t index = biSearch(a, left, right, med);

        detail::swap(a[(left + right) / 2], a[index]);

        size_t lenghtPart = detail::partition(a, left, right);
        //now pivot is a median of array
        if (k <= lenghtPart) {
            return kth_element_2(a, left, lenghtPart);
        }
        else {
            return kth_element_2(a, lenghtPart + 1, right);
        }
    }
}