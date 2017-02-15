#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_set>

using namespace std;

int main()
{
    ifstream fin("p042_words.txt");
    unordered_set<unsigned int> triangular;
    unsigned int tri_tot = 0;
    unsigned int tri_max = 0;
    unsigned int n_max = 0;

    if (fin.fail()) {
        return -1;
    }

    while (!fin.eof()) {
        char s[100];
        unsigned int wval = 0;

        fin.ignore(1);
        fin.get(s, sizeof(s), '"');
        fin.ignore(2);

        for (unsigned int i = 0; i < strlen(s); i++) {
            wval += s[i] - 'A' + 1;
        }

        /* Grow the collection of triangular number on demand */
        while (wval > tri_max) {
            n_max ++;
            tri_max = n_max * (n_max + 1) / 2;
            triangular.insert(tri_max);
        }

        if (triangular.count(wval)) {
            tri_tot ++;
        }
    }

    cout << "Number of triangular numbers: " << tri_tot << endl;

    return 0;
}
