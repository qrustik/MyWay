#pragma once
#include "detail.hpp"

namespace myalgo
{
    template <typename T>
    T kth_element(T a[], const size_t& k, const size_t& left, const size_t& right) {
        if ((right - left + 1) == 1) return a[0];

        size_t lenghtPart = detail::partition(a, left, right);
        // pivot is l + r / 2

        if (k <= lenghtPart) {
            return kth_element(a, left, lenghtPart);
        }
        else {
            return kth_element(a, lenghtPart + 1, right);
        }
    }
}
