#include <iostream>
#include <vector>
#include <array>
#include <random>
#include "mergesort.hpp"
#include "quicksort.hpp"
#include "insertionsort.hpp"

int main(int argc, char const* argv[])
{
    auto v = std::vector<int>{};
    auto v1 = std::vector<int>{};
    auto a = std::array<int, 200>{};
    size_t n = 1000;
    v.resize(n);
    v1.resize(n);

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis(0, n);

    for (int i = 0; i < v.size(); ++i) {
        v[i] = dis(gen);
        v1[i] = v[i];
    }

    for (auto&& i : v)
        std::cout << i << " ";

    myalgo::mergeSort<int>(v.data(), 0, v.size() - 1);

    std::cout << "\nMergesort\n";

    for (auto&& i : v) {
        std::cout << i << " ";
    }

    // std::cout << "\nQuicksort\n";

    // myalgo::quicksort(a.data(), 0, n - 1); // for vector sort dont working idk?

    // for (int i = 0; i < n; ++i)
    //      std::cout << a[i] << " ";

    myalgo::insertionSort<int>(v1.data(), v1.size());

    std::cout << "\nInsert sort:\n";

    for (auto&& i : v1) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    return 0;
}
