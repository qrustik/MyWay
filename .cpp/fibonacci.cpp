#include <iostream>
#include <cassert>

class Fibonacci
{
public:
    static size_t get(int n)
    {
        assert(n >= 0);

        if (n < 2)
            return n;

        size_t prev = 0;
        size_t cur = 1;
        for (size_t i = 2; i <= n; ++i)
        {
            size_t tmp = cur;
            cur = prev + cur;
            prev = tmp;
        }
        return cur;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Fibonacci::get(10) << std::endl;

    return 0;
}
