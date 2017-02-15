#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

using namespace std;

struct BT {
    int i;
    int j;
    string s;
    BT(int i0, int j0, string s0) : i(i0), j(j0), s(s0) { }
};

static void
compute_lcs(const string &a, const string &b, set<string>& lcses)
{
    int m[81][81];

    for (int i = 0; i <= max(a.size(), b.size()); i++) {
        m[0][i] = 0;
        m[i][0] = 0;
    }

    for (int i = 1; i <= a.size(); i ++) {
        for (int j = 1; j <= b.size(); j ++) {
            int best = m[i-1][j];

            best = max(best, m[i][j-1]);
            best = max(best, m[i-1][j-1] +
                             (a[i-1] == b[j-1] ? 1 : 0));
            m[i][j] = best;
        }
    }

/*
    for (int i = 1; i <= a.size(); i ++) {
        for (int j = 1; j <= b.size(); j ++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
*/

    stack<BT> st;

    st.push(BT(a.size(), b.size(), string()));

    while (!st.empty()) {
        BT bt = st.top();
        int i = bt.i;
        int j = bt.j;
        string s = bt.s;

        st.pop();

        if (i == 0 && j == 0) {
            lcses.insert(s);
            continue;
        }

        if (i > 0 && j > 0 && a[i-1] == b[j-1] &&
                m[i-1][j-1] + 1 == m[i][j]) {
            st.push(BT(i-1, j-1, a[i-1] + s));
        }

        if (j > 0 && m[i][j-1] == m[i][j]) {
            st.push(BT(i, j-1, s));
        }

        if (i > 0 && m[i-1][j] == m[i][j]) {
            st.push(BT(i-1, j, s));
        }
    }
}

int main()
{
    unsigned n;

    cin >> n;

    for (int i = 0; i < n; i ++) {
        string a, b;
        set<string> lcses;

        cin >> a >> b;

        compute_lcs(a, b, lcses);
        for (set<string>::iterator j = lcses.begin();
                                j != lcses.end(); j ++) {
            cout << *j << endl;
        }
        if (i < n-1) {
            cout << endl;
        }
    }

    return 0;
}

