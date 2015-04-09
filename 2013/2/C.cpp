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
#include <unordered_map>
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
auto rl() { return read<long long>(); };
auto ri() { return read<int>(); };
auto rd() { return read<double>(); };
auto rs() { return read<string>(); };

void test_case(int case_num)
{
    auto n = ri();
    vector<int> a(n);
    vector<int> b(n);

    for (auto& i: a)
    {
        i = ri();
    }
    for (auto& i: b)
    {
        i = ri();
    }

    vector<bool> lt(n - 1);
    cout << "a " << a[0] << " b " << b[0] << endl;
    for (auto i = 1; i < n; ++i)
    {
        cout << "a " << a[i] << " b " << b[i] << endl;
        if (a[i] == a[i-1] + 1)
        {
            cout << "true" << endl;
            lt[i] = true;
        }
        else if (a[i] == a[i-1] + 1)
        {
            cout << "false" << endl;
            lt[i] = false;
        }
        else if (b[i] == b[i - 1] - 1)
        {
            cout << "false" << endl;
            lt[i] = false;
        }
        else if (b[i] == b[i - 1] + 1)
        {
            cout << "true" << endl;
            lt[i] = true;
        }
    }
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
