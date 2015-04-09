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
    auto m = ri();
    vector<tuple<int, int, int>> rides(m);
    vector<int> entries(n, 0);
    vector<int> destinations(n, 0);
    for (auto i = 0; i < m; ++i)
    {
        rides[i] = make_tuple(ri(), ri(), ri());
    }
    sort(rides.begin(), rides.end(), [](auto l, auto r)
         {
             return get<0>(l) < get<0>(r);
         });
    auto r = rides.begin();
    for (auto i = 0; i < n; ++i)
    {
        auto gettingOn = 0;
        auto sw = entries.begin() + i - 1;
        while (get<0>(*r) == i)
        {
            auto p = get<2>(*r);
            gettingOn += p;
            destinations[get<1>(*r)] += p;
            ++r;
        }
        if (destinations[i] > gettingOn)
        {
        }
        else
        {
            entries[i] += gettingOn;
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
