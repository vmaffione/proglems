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
#if 0
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
#endif 0
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

         /* Push the couples into two vectors amd sort them: lpairs keeps them
          * ordered w.r.t. the first coordinate, rpairs keeps
          * them ordered w.r.t. the second coordinate. */
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

         /* Scan the sets in parallel (in ascending order, since
          * this is a set). */
        auto i = lpairs.begin();
        auto j = rpairs.begin();

        for (; i != lpairs.end();) {
            /* If the order of the couples so far is the same, keep
             * going, it means so far there are no intersections. */
            if (i->first == j->second /* or i->second == j->first */) {
                j ++;
                i ++;
                continue;
            }

            /* Otherwise we lineary-search where the i-th couple is
             * in rpairs. */
            auto k = j + 1;

            while (k != rpairs.end() && k->first != i->second) {
                k ++;
            }
            assert(k != rpairs.end());

            /* The number of intersections caused by k is the difference
             * between the position in rpairs and the one in lpairs. */
            total_moves += k - j;

            /* We move k right before j. */
            pair<unsigned, unsigned> x = *k;
            rpairs.erase(k);
            rpairs.insert(j, x);

            print_pairs(rpairs, false);
        }
        cout << "Case #" << tc << ": " << total_moves << endl;
    }

    return 0;
}
