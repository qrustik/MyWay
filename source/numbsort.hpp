
#pragma once
#include "detail.hpp"

namespace myalgo
{
    void cntsort(int a[], const int& max, const size_t& size) {
        int cnt[max] = {};
        for (size_t i = 0; i < size; ++i) {
            ++cnt[a[i]];
        }
        for (size_t i = 0, k = 0; i < max; ++i) {
            for (size_t j = 0; j < cnt[i]; j++) {
                a[k++] = i;
            }
        }
    }
}