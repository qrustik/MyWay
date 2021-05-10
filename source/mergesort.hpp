#pragma once

namespace myalgo
{
    namespace detail
    {
        template <typename T>
        void _merge(T a[], const size_t &left, const size_t &mid, const size_t &right, T _buf[])
        {
            size_t i = left,
                   j = mid + 1,
                   k = 0,
                   size = right - left + 1;

            for (i, j, k; i <= mid && j <= right;)
            {
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
        void _mergesort(T a[], const size_t &left, const size_t &right, T _buf[])
        {
            if (left == right)
                return;

            size_t mid = (left + right) / 2;
            _mergesort(a, left, mid, _buf);
            _mergesort(a, mid + 1, right, _buf);
            _merge(a, left, mid, right, _buf);
        }
    }

    template <typename T>
    static void mergesort(T a[], const size_t &left, const size_t &right)
    {
        T _buf[right - left + 1] = {};
        detail::_mergesort<T>(a, left, right, _buf);
    }
};