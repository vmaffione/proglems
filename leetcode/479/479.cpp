#include <iostream>
#include <string>

using namespace std;

class Solution {
    unsigned long lower(int n) {
        unsigned long mul = 1;

        for (unsigned i = 0; i < n-1; i++) {
            mul *= 10;
        }
        
        return mul;

    }

    bool is_palindrom(unsigned long x) {
        string rr = to_string(x);

        int i, j;
        
        i = 0;

        j = rr.size() - 1;
        while (i < j && rr[i] == rr[j]) {
            i ++;
            j --;
        }

        return (i < j) ? false : true;
    }

public:

    int largestPalindrome(int n) {
        unsigned long low = lower(n);
        unsigned long high = low * 10;

        for (unsigned long i = high-1; i >= low; i--) {
            for (unsigned long k = 0; k < high - i; k++) {
                unsigned long x = (i + k) * (high-1 - k);

                if (is_palindrom(x)) {
                    return x % 1337;
                }
            }
        }

        return 0;

    }

};

int main()
{
    Solution s;
    unsigned long x;
    x = s.largestPalindrome(8);
    cout << x << endl;
    return 0;
}
