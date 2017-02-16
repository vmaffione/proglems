#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

static long unsigned
min_meaning(const string& m)
{
    unordered_map<char, unsigned> c2d;
    unsigned b = 0;
    char c1 = '0';

    assert(m.size() > 0);

    for (unsigned i = 0; i < m.size(); i ++) {
        if (c2d.find(m[i]) == c2d.end()) {
            if (b == 1) {
                c1 = m[i]; /* remember the char assigned to 1 */
            }
            c2d[m[i]] = b ++;
        }
    }

    if (b == 1) {
        /* We know b is at least 2, so let's fix it. */
        b = 2;
        c2d[m[0]] = 1;
    } else {
        /* Fix the not-starting-with-zero problem, by
         * swapping the mapping for digits 1 and 0. */
        c2d[c1] = 0;
        c2d[m[0]] = 1;
    }

    unsigned long value = 0;
    unsigned long mul = 1;

    for (int i = m.size()-1; i >= 0; i --) {
        value += c2d[m[i]] * mul;
        mul *= b;
    }

    return value;
}

int main()
{
    int t;

    cin >> t;

    for (unsigned ct = 1; ct <= t; ct ++) {
        string s;

        cin >> s;

        cout << "Case #" << ct << ": " << min_meaning(s) << endl;
    }

    return 0;
}
