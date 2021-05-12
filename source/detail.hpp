#pragma once

namespace detail
{
    // General

    template <typename T>
    void swap(T& first, T& second) {
        T tmp = first;
        first = second;
        second = tmp;
    }


    // For merge sort

    template <typename T>
    void _merge(T a[], const size_t& left, const size_t& mid, const size_t& right, T _buf[]) {
        size_t i = left,
            j = mid + 1,
            k = 0,
            size = right - left + 1;

        for (i, j, k; i <= mid && j <= right;) {
            if (a[i] < a[j])
                _buf[k++] = a[i++];
            else
                _buf[k++] = a[j++];
        }

        while (i <= mid)
            _buf[k++] = a[i++];

        while (j <= right)
            _buf[k++] = a[j++];

        for (size_t i = 0, j = left; i < size; ++i, ++j)
            a[j] = _buf[i];
    }

    template <typename T>
    void _mergesort(T a[], const size_t& left, const size_t& right, T _buf[]) {
        if (left == right)
            return;

        size_t mid = (left + right) / 2;
        _mergesort(a, left, mid, _buf);
        _mergesort(a, mid + 1, right, _buf);
        _merge(a, left, mid, right, _buf);
    }


    // For quick sort

    template <typename T>
    size_t partition(T a[], const size_t& l, const size_t& r) {
        T v = a[(l + r) / 2];
        size_t i = l;
        size_t j = r;
        while (i <= j) {
            while (a[i] < v)
                ++i;
            while (a[j] > v)
                --j;
            if (i >= j)
                break;
            swap<T>(a[i++], a[j++]);
        }
        return j;
    }


    // For determined functions

    template<typename T>
    size_t median(T a[], const size_t& left, const size_t& right)
    {
        size_t size = (right - left + 1);
        size_t parts = size / 5;
        size_t medians[parts + 1] = {};

        for (size_t i = left + 5, m = 0; i <= right; i += 5) {
            size_t index = i - 5;
            for (size_t j = index + 1; j < i; j++) {
                size_t k = j;
                while ((a[k] < a[k - 1]) && (k >= index)) {
                    swap(a[k], a[k - 1]);
                    --k;
                }
            }
            medians[m++] = a[i - 3];
        }

        size_t index = parts * 5;

        for (size_t i = index + 1; i < size; ++i) {
            size_t j = i;
            while (a[j] < a[j - 1] && j >= index) {
                swap(a[j], a[j - 1]);
                --j;
            }
        }

        for (size_t i = 1; i < parts + 1; ++i) {
            size_t j = i;
            while (medians[j] < medians[j - 1] && j >= 0) {
                swap(medians[j], medians[j - 1]);
                --j;
            }
        }

        return medians[parts + 1 / 2];
    }


}