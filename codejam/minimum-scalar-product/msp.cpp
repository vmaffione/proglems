#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool invcomp(int a, int b)
{
    return a > b;
}

int main()
{
    int t;

    cin >> t;

    for (unsigned c = 0; c < t; c ++) {
        vector<int> x, y;
        unsigned n;

        cin >> n;

        for (unsigned j = 0; j < n; j ++) {
            int u;
            cin >> u;
            x.push_back(u);
        }

        for (unsigned j = 0; j < n; j ++) {
            int u;
            cin >> u;
            y.push_back(u);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end(), invcomp);

        long int sp = 0;

        for (unsigned j = 0; j < n; j ++) {
            sp += x[j] * y[j];
        }

        cout << "Case #" << c+1 << ": " << sp << endl;
    }

    return 0;
}
