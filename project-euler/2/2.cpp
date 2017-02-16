#include <iostream>

int main()
{
    unsigned long sum = 0;

    for (unsigned long a = 1, b = 2; a <= 4000000; ) {
        unsigned long c;

        if ((a & 1) == 0) {
            sum += a;
        }

        c = a + b;
        a = b;
        b = c;
    }

    std::cout << "Sum of even Fibonacci numbers not exceeding 4 millions: "
                << sum << std::endl;

    return 0;
}
