#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cassert>

using namespace std;

static void
print_pairs(const vector<pair<unsigned, unsigned> >& pairs,
            bool left)
{
        if (left) {
            cout << "Lpairs: " << endl;
        } else {
            cout << "Rpairs: " << endl;
        }

        for (auto j = pairs.begin(); j != pairs.end(); j++) {
            if (left) {
                cout << "    " << j->first << ", " << j->second << endl;
            } else {
                cout << "    " << j->second << ", " << j->first << endl;
            }
        }
}

int main()
{
    unsigned t;

    cin >> t;

    for (unsigned tc = 1; tc <= t; tc ++) {
        vector<pair<unsigned, unsigned> > lpairs, rpairs;
        unsigned total_moves = 0;
        unsigned n;

        cin >> n;

        for (unsigned j = 0; j < n; j ++) {
            unsigned a, b;

            cin >> a >> b;
            lpairs.push_back(make_pair(a, b));
            rpairs.push_back(make_pair(b, a));
        }

        sort(lpairs.begin(), lpairs.end());
        sort(rpairs.begin(), rpairs.end());


        print_pairs(lpairs, true);
        print_pairs(rpairs, false);

        auto i = lpairs.begin();
        auto j = rpairs.begin();

        for (; i != lpairs.end();) {
            if (i->first == j->second /* or i->second == j->first */) {
                j ++;
                i ++;
                continue;
            }

            auto k = j + 1;

            while (k != rpairs.end() && k->first != i->second) {
                k ++;
            }
            assert(k != rpairs.end());

            total_moves += k - j;

            pair<unsigned, unsigned> x = *k;
            rpairs.erase(k);
            rpairs.insert(j, x);

            print_pairs(rpairs, false);
        }
        cout << "Case #" << tc << ": " << total_moves << endl;
    }

    return 0;
}
