#include <iostream>
#include <string>

using namespace std;

static bool
is_palindrom(const string& s)
{
    int i = 0, j = s.size() - 1;

    while (i < j && s[i] == s[j]) {
        i ++;
        j --;
    }

    return (i < j) ? false : true;
}

static bool
is_palindrom(unsigned x)
{
    string s;

    while (x) {
        char c = '0' + (x % 10);

        s.push_back(c);
        x /= 10;
    }

    return is_palindrom(s);
}

int main()
{
    unsigned m = 0;

    for (unsigned x = 100; x < 999; x ++) {
        for (unsigned y = x; y < 1000; y ++) {
            unsigned z = x * y;

            if (z > m && is_palindrom(z)) {
                m = z;
            }
        }
    }

    cout << "Largest palindrome made from the product of two 3-digit numbers: " << m << endl;

    return 0;
}
