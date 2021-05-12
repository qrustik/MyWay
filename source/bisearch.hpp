#pragma once

namespace myalgo
{
    template<typename T>
    size_t biSearch(const T a[], size_t left, size_t right, const size_t& value) {
        size_t mid = (left + right) / 2;
        while (right - left > 1) {
            if (a[mid] >= value) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return right;
    }
}