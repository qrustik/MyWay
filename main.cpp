#include <iostream>
#include <vector>
#include <array>
#include <random>
#include "myalgo.hpp"

int main(int argc, char const *argv[])
{
    auto v = std::vector<int>{};
    auto a = std::array<int, 50>{};
    size_t n = 50;
    v.resize(n);

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis(0, n);

    // std::cout << b.size() << " " << a.size() << "\n";

    for (int i = 0; i < v.size(); ++i)
    {
        v[i] = dis(gen);
        a[i] = v[i];
    }

    for (auto &&i : v)
        std::cout << i << " ";

    myalgo::mergesort<int>(v.data(), 0, v.size() - 1);

    std::cout << "\nMergesort\n";

    for (auto &&i : v)
        std::cout << i << " ";

    std::cout << "\nQuicksort\n";

    myalgo::quicksort(a.data(), 0, n - 1); // for vector sort dont working idk?

    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " ";

    std::cout << std::endl;
    return 0;
}
