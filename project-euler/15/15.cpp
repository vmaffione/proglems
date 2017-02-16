#include <iostream>
#include <string>

using namespace std;

static const int N = 20;

int main()
{
    unsigned long m[N][N];

    for (unsigned i = 0; i < N; i ++) {
        m[i][0] = m[0][i] = i + 2;
    }

    for (unsigned i = 1; i < N; i ++) {
        for (unsigned j = 1; j < N; j ++) {
            m[i][j] = m[i-1][j] + m[i][j-1];
        }
    }

    cout << "Number of possible routes: " << m[N-1][N-1] << endl;

    return 0;
}
