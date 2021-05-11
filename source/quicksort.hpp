#pragma once
#include "mergesort.hpp"

namespace myalgo
{
    namespace detail
    {

        template <typename T>
        void swap(T& first, T& second) {
            T tmp = first;
            first = second;
            second = tmp;
        }

        template <typename T>
        int partition(T a[], const size_t& l, const size_t& r) {
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

    template <typename T>
    void quicksort(T a[], size_t l, size_t r) {
        if (r - l < 11) {
            mergesort<T>(a, l, r);
            return;
        }

        detail::swap<T>(a[detail::median<T>(a, l, r)], a[(r + l) / 2]);

        size_t i = detail::partition<T>(a, l, r);

        quicksort<T>(a, l, i);
        quicksort<T>(a, i + 1, r);
    }
}