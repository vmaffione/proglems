#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

static void
generate_perm(int n, stack<char>& st, vector<bool>& marked, int& cnt)
{
    if (n <= 0) {
        cnt ++;
        if (cnt == 1000000) {
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

    for (unsigned i = 0; i < marked.size(); i ++) {
        if (!marked[i]) {
            marked[i] = true;
            st.push(i);
            generate_perm(n-1, st, marked, cnt);
            st.pop();
            marked[i] = false;
        }
    }
}

int main()
{
    vector<bool> marked(10);
    int perm_cnt = 0;
    stack<char> st;

    for (unsigned i = 0; i < marked.size(); i ++) {
        marked[i] = false;
    }

    generate_perm(10, st, marked, perm_cnt);

    return 0;
}
