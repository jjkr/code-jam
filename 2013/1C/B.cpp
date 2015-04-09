#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace
{
template <typename T>
auto read()
{
    T i;
    cin >> i;
    return i;
}
auto ri() { return read<int>(); };
auto rd() { return read<double>(); };
auto rs() { return read<string>(); };

void test_case(int case_num)
{
    auto x = ri();
    auto y = ri();

    auto sumxy = abs(x) + abs(y);
    auto n = 0;
    auto nsum = 0;
    while (nsum < sumxy || ((nsum + x + y) % 2 == 1))
    {
        ++n;
        nsum += n;
    }

    //cout << "x " << x << " y " << y << " n " << n << endl;

    vector<char> dirs;
    while (n>0)
    {
        if (abs(x) > abs(y))
        {
            if (x > 0)
            {
                dirs.push_back('E');
                x -= n;
            }
            else
            {
                dirs.push_back('W');
                x += n;
            }
        }
        else
        {
            if (y > 0)
            {
                dirs.push_back('N');
                y -= n;
            }
            else
            {
                dirs.push_back('S');
                y += n;
            }
        }
        //cout << "x " << x << " y " << y << " n " << n << " dir "
             //<< *(dirs.end() - 1) << endl;
        --n;
    }
    string s(dirs.crbegin(), dirs.crend());
    cout << s;
}
}

int main()
{
    auto num_cases = ri();
    cout << fixed << setprecision(7);
    for (auto i = 0; i < num_cases; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        test_case(i);
        cout << endl;
    }
}
