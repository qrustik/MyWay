#include <iostream>
#include

template <typename vType>
int biSearch(const vType *a, const size_t &length, const vType &val)
{
    size_t beg = 0;
    size_t end = length;
    size_t m = 0;
    while (end - beg > 1)
    {
        m = beg + (beg + end) / 2;
        if (a[m] >= val)
            end = m;
        else
            beg = m;
    }
    return end;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 4, 9, 16, 25, 36, 49, 64, 81};
    size_t lenght = 9;
    int index = biSearch<int>(a, lenght, 5);
    std::cout << index << " " << a[index] << std::endl;
    return 0;
}
