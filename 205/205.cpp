#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


static void
random_variable_print(const unordered_map<int, double>& x)
{
    for (unordered_map<int, double>::const_iterator i = x.begin();
                                                    i != x.end(); i ++) {
        cout << i->first << "-->" << i->second << ", ";
    }
    cout << endl;
}

unordered_map<int, double>
random_variable_add(const unordered_map<int, double>& x,
                    const unordered_map<int, double>& y)
{
    unordered_map<int, double> result;

    for (unordered_map<int, double>::const_iterator i = x.begin();
                                                    i != x.end(); i ++) {
        for (unordered_map<int, double>::const_iterator j = y.begin();
                                                        j != y.end(); j ++) {
            unsigned sum = i->first + j->first;

            if (result.count(sum) == 0) {
                result[sum] = 0.0;
            }
            result[sum] += i->second * j->second;
        }
    }

    return result;
}

unordered_map<int, double>
random_variable_sub(const unordered_map<int, double>& x,
                    const unordered_map<int, double>& y)
{
    unordered_map<int, double> y_inv;

    for (unordered_map<int, double>::const_iterator i = y.begin();
                                                    i != y.end(); i ++) {
        y_inv[-i->first] = i->second;
    }

    return random_variable_add(x, y_inv);
}

int main()
{
    unordered_map<int, double> peter_roll, colin_roll,
                               peter_rolls, colin_rolls,
                               result;
    double p = 0.0;

    /* Basic die distribution for Peter and Colin. */
    for (unsigned i = 1; i <= 4; i ++) {
        peter_roll[i] = 1.0/4;
    }

    for (unsigned i = 1; i <= 6; i ++) {
        colin_roll[i] = 1.0/6;
    }

    peter_rolls = peter_roll;
    for (unsigned i = 0; i < 8; i ++) {
        peter_rolls = random_variable_add(peter_rolls, peter_roll);
    }
    colin_rolls = colin_roll;
    for (unsigned i = 0; i < 5; i ++) {
        colin_rolls = random_variable_add(colin_rolls, colin_roll);
    }

    random_variable_print(peter_rolls);
    random_variable_print(colin_rolls);

    result = random_variable_sub(peter_rolls, colin_rolls);
    random_variable_print(result);

    for (unordered_map<int, double>::const_iterator
                    i = result.begin(); i != result.end(); i ++) {
        if (i->first > 0) {
            p += i->second;
        }
    }

    cout << "Total probability: " << p << endl;
    printf("%.9f\n", p);

    return 0;
}
