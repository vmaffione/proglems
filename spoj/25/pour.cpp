#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

struct Node {
    int va;
    int vb;
    int steps;

    Node(int x = 0, int y = 0, int s = 0) : va(x), vb(y), steps(s) { }
    unsigned int key() const { return va * 40001 + vb; }
};

static void
vessels(int a, int b, int c)
{
    unordered_set<unsigned> marked;
    queue<Node> frontier;

    frontier.push(Node(0, 0, 0));
    marked.insert(frontier.front().key());

    while (!frontier.empty()) {
        Node cur = frontier.front();
        vector<Node> nexts;

        frontier.pop();
#if 0
        cout << "visiting " << cur.va << ", " << cur.vb << ", " << cur.steps << endl;
#endif
        if (cur.va == c || cur.vb == c) {
            /* Solution found. */
            cout << cur.steps << endl;
            return;
        }

        /* Generate next states. */
        if (cur.va) {
            /* empty va */
            nexts.push_back(Node(0, cur.vb, cur.steps + 1));
        }

        if (cur.vb) {
            /* empty vb */
            nexts.push_back(Node(cur.va, 0, cur.steps + 1));
        }

        if (cur.va < a) {
            /* fill va */
            nexts.push_back(Node(a, cur.vb, cur.steps + 1));
        }

        if (cur.vb < b) {
            /* fill vb */
            nexts.push_back(Node(cur.va, b, cur.steps + 1));
        }

        if (cur.va && cur.vb < b) {
            /* pour va into vb */
            int x = min(b - cur.vb, cur.va);
            nexts.push_back(Node(cur.va - x, cur.vb + x, cur.steps + 1));
        }

        if (cur.vb && cur.va < a) {
            /* pour vb into va */
            int x = min(a - cur.va, cur.vb);
            nexts.push_back(Node(cur.va + x, cur.vb - x, cur.steps + 1));
        }

        for (unsigned i = 0; i < nexts.size(); i ++) {
            unsigned int key = nexts[i].key();

            if (marked.count(key) == 0) {
                marked.insert(key);
                frontier.push(nexts[i]);
            }
        }
    }

    cout << -1 << endl;
}

int main()
{
    unsigned n;

    cin >> n;

    for (unsigned i = 0; i < n; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        vessels(a, b, c);
    }

    return 0;
}
