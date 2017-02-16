#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Node {
public:
    string dir;
    unordered_map<string, Node *> children;
    Node(const string& x) : dir(x) { }

    pair<Node *, bool> child_add(const string& x) {
        auto p = make_pair(x, new Node(x));
        auto ret = children.insert(p);
        bool added = ret.second;

        if (!added) {
            delete p.second;
        }

        return make_pair(ret.first->second, added);
    }
};

static int
trie_add(Node& trie, const string& path)
{
    bool quit = false;
    Node *cur = &trie;
    int count = 0;
    int pos = 1;

    while (!quit) {
        int idx = path.find('/', pos);
        string dirname;
        Node *child;

        if (idx == string::npos) {
            quit = true;
            idx = path.size();
        }

        dirname = path.substr(pos, idx - pos);
        pos = idx + 1;

        auto i = cur->children.find(dirname);

        if (i == cur->children.end()) {
            Node *child = new Node(dirname);

            cur->children[dirname] = child;
            cur = child;
            count ++;
        } else {
            cur = i->second;
        }
    }

    return count;
}

int main()
{
    int t;

    cin >> t;

    for (int ct = 1; ct <= t; ct ++) {
        Node trie("");
        int n, m;
        int count = 0;

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            string path;

            cin >> path;
            trie_add(trie, path);
        }

        for (int i = 0; i < m; i++) {
            string path;

            cin >> path;
            count += trie_add(trie, path);
        }

        cout << "Case #" << ct << ": " << count << endl;
    }

    return 0;
}
