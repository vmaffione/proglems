#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

inline unsigned int
max(unsigned int a, unsigned int b)
{
    return a < b ? b : a;
}

inline unsigned int
product(unsigned int m[20][20], int i, int j, int inci, int incj)
{
    return m[i][j] * m[i + inci][j + incj] *
            m[i + 2*inci][j + 2*incj] * m[i + 3*inci][j + 3*incj];
}

int main()
{
    ifstream fin("input.txt");
    unsigned int m[20][20];
    unsigned int gp = 0;

    if (fin.fail()) {
        return -1;
    }

    for (int i = 0, j = 0; !fin.eof();) {
        unsigned int x;

        fin >> x;
        if (fin.eof()) {
            break;
        }

        m[i][j] = x;
        j ++;
        if (j == 20) {
            j = 0;
            i ++;
        }
    }

    for (int i = 0; i < 20; i ++) {
        for (int j = 0; j < 20; j ++) {

            if (j + 3 < 20) { /* horizontal */
                gp = max(gp, product(m, i, j, 0, 1));
            }

            if (i + 3 < 20) { /* vertical */
                gp = max(gp, product(m, i, j, 1, 0));
            }

            if (i + 3 < 20 && j + 3 < 20) { /* diagonal 1 */
                gp = max(gp, product(m, i, j, 1, 1));
            }

            if (i + 3 < 20 && j-3 >= 0) { /* diagonal 2 */
                gp = max(gp, product(m, i, j, 1, -1));
            }
        }
    }

    cout << "Greatest product of four adjacent numbers is: " << gp << endl;

    return 0;
}
