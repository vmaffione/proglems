#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_set>
#include <vector>

using namespace std;

static void
fill_digit_array(unsigned x, int xd[10])
{
    for (unsigned i = 0; i < 10; i ++) {
        xd[i] = 0;
    }

    while (x) {
        xd[x % 10] ++;
        x /= 10;
    }
}

static bool
is_perm(unsigned int x, unsigned int y)
{
    int xd[10];
    int yd[10];

    fill_digit_array(x, xd);
    fill_digit_array(y, yd);

    for (unsigned i = 0; i < 10; i ++) {
        if (xd[i] != yd[i]) {
            return false;
        }
    }

    return true;
}

int main()
{
    unordered_set<unsigned int> primes;
    vector<bool> criv(10000);

    /* Erathostenes */
    for (unsigned i = 2; i < 5000; i ++) {
        if (criv[i]) {
            /* not a prime, we can skip */
            continue;
        }

        for (unsigned j = 2*i; j < 10000; j += i) {
            criv[j] = true;
        }
    }

    for (unsigned i = 2; i < 10000; i++) {
        if (!criv[i]) {
            primes.insert(i);
        }
    }

    for (unordered_set<unsigned int>::iterator s = primes.begin();
                                        s != primes.end(); s ++) {
        for (unsigned int d = 1; true; d ++) {
            int m, l;

            m = *s + d;
            l = m + d;

            if (l > 9999 || m > 9999) {
                break;
            }

            if (primes.count(l) && primes.count(m) && is_perm(*s, m)
                    && is_perm(m, l)) {
                cout << *s << "," << m << "," << l << endl;
            }
        }
    }

    return 0;
}
