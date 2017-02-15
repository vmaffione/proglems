#include <iostream>

using namespace std;

int main()
{
    while (!cin.eof()) {
        int x;

        cin >> x;

        if (x == 42) {
            break;
        }

        cout << x << endl;
    }

    return 0;
}
