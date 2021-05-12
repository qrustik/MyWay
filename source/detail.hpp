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

    template <typename T>
    size_t median(const T a[], const size_t& l, const size_t& r) {
        size_t tmp[3] = { l, (r + l) / 2, r };
        while (!(a[tmp[1]] >= a[tmp[0]] && a[tmp[1]] <= a[tmp[2]])) {
            if (a[tmp[1]] > a[tmp[0]]) {
                swap<size_t>(tmp[0], tmp[1]);
            }
            else if (a[tmp[1]] < a[tmp[2]]) {
                swap<size_t>(tmp[1], tmp[2]);
            }
            else if (a[tmp[0]] > a[tmp[2]]) {
                swap<size_t>(tmp[0], tmp[2]);
            }
        }
        return tmp[1];
    }



}