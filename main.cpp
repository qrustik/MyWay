#include <iostream>
#include <vector>
#include <random>
#include "myalgo.hpp"

int main(int argc, char const *argv[])
{
    auto a = std::vector<int>{};
    size_t n = 50;
    a.resize(n);

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis(0, n);

    for (int i = 0; i < a.size(); ++i)
        a[i] = dis(gen);

    for (auto &&i : a)
        std::cout << i << " ";

    myalgo::mergesort<int>(a.data(), 0, a.size() - 1);

    std::cout << "\n";

    for (auto &&i : a)
        std::cout << i << " ";

    std::cout << std::endl;
    return 0;
}
