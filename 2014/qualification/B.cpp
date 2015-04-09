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

template<typename T>
auto read()
{
    T i;
    cin >> i;
    return i;
}
auto ri() { return read<int>(); };
auto rd() { return read<double>(); };

void test_case(int case_num)
{
    auto c = rd();
    auto f = rd();
    auto x = rd();

    auto rate = 2.0;
    auto time = 0.0;

    if (c > x)
    {
        cout << fixed << setprecision(7) << x/rate;
        return;
    }

    while (true)
    {
        auto nextHouseTime = c/rate;
        auto nextRate = rate + f;
        auto finTime = x/rate;
        if (finTime < nextHouseTime + x/nextRate)
        {
            cout << fixed << setprecision(7) << time + finTime;
            return;
        }
        rate = nextRate;
        time += nextHouseTime;
    }
}
}

int main()
{
    auto num_cases = ri();
    cout << fixed << setprecision(7);
    for (auto i = 0; i < num_cases; ++i)
    {
        cout << "Case #" << i+1 << ": ";
        test_case(i);
        cout << endl;
    }
}
