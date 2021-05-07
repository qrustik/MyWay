#include <iostream>
#include <random>

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


int main(int argc, char const *argv[])
{
    size_t N = 100;
    int a[N] = {};

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis(0,1000);

    std::cout << "Unsorted:\n";
    for (size_t i = 0; i < N; i++)
    {
        a[i] = dis(gen);
        std::cout << a[i] << " ";
    }

    MergeSort<int>(a, 0, N - 1);

    std::cout << "\nSorted:\n";
    for (size_t i = 0; i < N; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
