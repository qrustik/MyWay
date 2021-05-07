#include <iostream>
#include <random>
#include <array>
#include <algorithm>
#include <cstdlib>

template <typename T>
void Merge(T a[], size_t left, size_t mid, size_t right)
{
    size_t size = right - left + 1;
    T buf[size] = {};
    size_t i = left;
    size_t j = mid + 1;
    size_t k = 0;
    for (i, j, k; i <= mid && j <= right;)
    {
        if (a[i] < a[j])
            buf[k++] = a[i++];
        else
            buf[k++] = a[j++];
    }
    while (i <= mid)
        buf[k++] = a[i++];
    while (j <= right)
        buf[k++] = a[j++];

    for (size_t i = 0, j = left; i < size; ++i, ++j)
        a[j] = buf[i];
}

template <typename T>
void MergeSort(T a[], size_t left, size_t right)
{
    if (left == right)
        return;
    size_t mid = (left + right) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

template<typename T>
int Partition(T a[],const size_t &l,const size_t &r) {
    T v = a[(l + r)/2];
    size_t i = l;
    size_t j = r;
    while(i <= j)
    {
        while(a[i] < v)
            ++i;
        while(a[j] > v)
            --j;
        if  (i >= j)
            break;
        T t = a[i];
        a[i++] = a[j];
        a[j++] = t;
    }
    return j;
}

template <typename T>
void QuickSort(T a[], size_t l, size_t r)
{
    if (r - l < 11)
    {
        MergeSort<T>(a, l, r);
        return;
    }

    size_t tmp[3] = {l, (r + l) / 2, r};
    while (!(a[tmp[1]] >= a[tmp[0]] && a[tmp[1]] <= a[tmp[2]]))
    {
        size_t t = 0;
        if (a[tmp[1]] > a[tmp[0]])
        {
            t = tmp[0];
            tmp[0] = tmp[1];
            tmp[1] = t;
        }
        else if (a[tmp[1]] < a[tmp[2]])
        {
            t = tmp[1];
            tmp[1] = tmp[2];
            tmp[2] = t;
        }
        else if (a[tmp[0]] > a[tmp[2]])
        {
            t = tmp[0];
            tmp[0] = tmp[2];
            tmp[2] = t;
        }
    }

    size_t med = tmp[1];

    T t = a[med];
    a[med] = a[(r + l)/2];
    a[(r + l)/2] = t;

    size_t i = Partition<T>(a, l, r);
    QuickSort<T>(a, l, i);
    QuickSort<T>(a, i + 1, r);
}

int main(int argc, char const *argv[])
{
    size_t N = 100;
    std::array<int, 100> a = {};
    std::array<int, 100> b = {};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);

    std::cout << "Unsorted:\n";
    for (size_t i = 0; i < N; i++)
    {
        a[i] = dis(gen);
        b[i] = a[i];
        std::cout << a[i] << " ";
    }

    QuickSort<int>(a.data(), 0, a.size() - 1);

    std::sort(b.begin(), b.end());

    std::cout << "\nSorted:\n";
    for (size_t i = 0; i < N; i++)
        std::cout << a[i] << " ";
    std::cout << "\nSorted:\n";
    for (size_t i = 0; i < N; i++)
        std::cout << b[i] << " ";

    std::cout << std::endl;

    return 0;
}
