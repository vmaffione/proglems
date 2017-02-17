/* A string consists of ‘0’, ‘1’ and '?'. The question mark can be
 * either '0' or '1'. Find all possible combinations for a string. */

#include <iostream>
#include <string>

using namespace std;

void gen_strings(const string& s, int n)
{
    while (n < s.size() && s[n] != '?') n ++;
    if (n == s.size()) {
        cout << s << endl;
    } else {
        string s2 = s;

        s2[n] = '0';
        gen_strings(s2, n+1);
        s2[n] = '1';
        gen_strings(s2, n+1);
    }
}

int main()
{
    string x = "01?1?0";

    gen_strings(x, 0);
    return 0;
}
