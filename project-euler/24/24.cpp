#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define DIGITS          10
#define SELECT_PERM     1000000

vector<unsigned long> factorials;

static void
generate_perm(int n, stack<char>& st, vector<bool>& marked, int& cnt)
{
    if (n <= 0) {
        cnt ++;
        if (cnt == SELECT_PERM) {
            stack<char> t = st;
            string s;

            while (!t.empty()) {
                s.push_back('0' + t.top());
                t.pop();
            }
            reverse(s.begin(), s.end());
            cout << s << endl;
        }
        return;
    }

    for (unsigned i = 0; i < marked.size() && cnt < SELECT_PERM; i ++) {
        if (!marked[i]) {
            if (cnt + factorials[n-1] < SELECT_PERM) {
                /* Just skip them */
                cnt += factorials[n-1];
            } else {
                marked[i] = true;
                st.push(i);
                generate_perm(n-1, st, marked, cnt);
                st.pop();
                marked[i] = false;
            }
        }
    }
}

int main()
{
    vector<bool> marked(DIGITS);
    int perm_cnt = 0;
    stack<char> st;

    /* Precompute factorials */
    factorials.push_back(1 /* 0! */);
    for (unsigned i = 1; i <= DIGITS; i ++) {
        factorials.push_back(factorials[i-1] * i);
    }

    for (unsigned i = 0; i < DIGITS; i ++) {
        marked[i] = false;
    }

    generate_perm(DIGITS, st, marked, perm_cnt);

    return 0;
}
