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
set_join(set<string>& cur, const set<string>& more, string *add)
{
    for (set<string>::iterator i = more.begin(); i != more.end(); i++) {
        if (add) {
            cur.insert((*i) + *add);
        } else {
            cur.insert(*i);
        }
    }
}

static void
compute_lcs(const string &a, const string &b, set<string>& lcses)
{
    int m[81][81];
    set<string> s[81][81];
    int r = a.size();
    int c = b.size();

    for (int i = 0; i <= max(r, c); i++) {
        m[0][i] = 0;
        m[i][0] = 0;
        s[0][i].insert(string());
        s[i][0].insert(string());
    }

    /* Memory footprint can be improved by storing only the last row */

    for (int i = 1; i <= r; i ++) {
        for (int j = 1; j <= c; j ++) {
            int best = m[i-1][j];

            best = max(best, m[i][j-1]);
            best = max(best, m[i-1][j-1] +
                             (a[i-1] == b[j-1] ? 1 : 0));
            m[i][j] = best;

            if (m[i][j] == m[i][j-1]) {
                set_join(s[i][j], s[i][j-1], NULL);
            }
            if (m[i][j] == m[i-1][j]) {
                set_join(s[i][j], s[i-1][j], NULL);
            }
            if (m[i][j] == 1 + m[i-1][j-1] && a[i-1] == b[j-1]) {
                string x;
                x.push_back(a[i-1]);
                set_join(s[i][j], s[i-1][j-1], &x);
            }
        }
    }

#if 0
    for (int i = 1; i <= r; i ++) {
        for (int j = 1; j <= c; j ++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif

    lcses = s[r][c];

#if 0
    /* Backtracking is very slow!! */
    stack<BT> st;

    st.push(BT(r, c, string()));

    while (!st.empty()) {
        BT bt = st.top();
        int i = bt.i;
        int j = bt.j;
        string s = bt.s;

        st.pop();
        cout << "visit " << i << ", " << j << endl;

        if (i == 0 && j == 0) {
            lcses.insert(s);
            cout << s << endl;
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
    cout << endl;
#endif
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

