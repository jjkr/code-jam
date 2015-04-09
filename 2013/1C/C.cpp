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

struct Tribe
{
    int d;
    int n;
    int w;
    int e;
    int s;
    int dd;
    int dp;
    int ds;
};

void test_case(int case_num)
{
    auto n = ri();
    vector<Tribe> tribes(n);
    for (auto& t: tribes)
    {
        t.d = ri();
        t.n = ri();
        t.w = ri();
        t.e = ri();
        t.s = ri();
        t.dd = ri();
        t.dp = ri();
        t.ds = ri();
    }
    sort(tribes.begin(), tribes.end(), [](auto& l, auto& r)
         {
             return l.d + l.n * l.dd > r.d + r.n * r.dd;
         });

    auto day = 0;
    unordered_map<int, int> wall;
    auto total = 0;
    auto testcount = 0;
    while (!tribes.empty() && testcount < 50)
    {
        ++testcount;
        auto done = 0;
        for (auto& t : tribes)
        {
            if (t.d <= day && ((day - t.d) % t.dd) == 0)
            {
                auto attack = (t.d + day) / t.dd;
                auto deltae = attack * t.dp;
                auto west = t.w + deltae;
                auto east = t.e + deltae;
                auto strength = t.s + attack * t.ds;
                auto success = false;
                cout << "tribe attack " << attack << " west " << west
                     << " east " << east << " strength " << strength << " day "
                     << day << " t.n " << t.n << endl;
                for (auto i = west; i <= east; ++i)
                {
                    if (wall.find(i) == wall.end())
                    {
                        wall.insert(make_pair(i, strength));
                        if (!success)
                        {
                            cout << " success!" << endl;
                            success = true;
                            ++total;
                        }
                    }
                    else if (wall[i] < strength)
                    {
                        wall[i] = strength;
                        if (!success)
                        {
                            success = true;
                            ++total;
                        }
                    }
                }
                if (attack == t.n)
                {
                    ++done;
                }
            }
        }
        for (auto i = 0; i < done; ++i)
        {
            tribes.pop_back();
        }

        ++day;
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
