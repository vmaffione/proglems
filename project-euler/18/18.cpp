#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<long> table;
    long maxsum = 0;

    for (int n = 1;; n++) {
        vector<long> next_table(n);
        vector<long> row;

        for (int i = 0; i < n; i ++) {
            int x;

            cin >> x;
            if (cin.eof()) {
                break;
            }
            row.push_back(x);
        }

        if (cin.eof()) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cout << row[i] << " ";
        }
        cout << endl;

        if (n == 1) { /* base case */
            table = row;
            continue;
        }

        for (int i = 0; i < n; i ++) {
            if (i == 0) {
                next_table[i] = table[i] + row[i];
            } else if (i == n-1) {
                next_table[i] = table[i-1] + row[i];
            } else {
                next_table[i] = row[i] + max(table[i], table[i-1]);
            }
        }

        table = next_table;
    }

    for (unsigned i = 0; i < table.size(); i ++) {
        maxsum = max(maxsum, table[i]);
    }

    cout << "Maximum sum of a route: " << maxsum << endl;

    return 0;
}
