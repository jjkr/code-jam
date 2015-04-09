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
    auto n = rl();
    auto k = rl();

    if (k == 0)
    {
        cout << "OFF";
        return;
    }

    auto m = (1ll << n);
    auto mod = k % m;
    cout << (mod == m - 1 ? "ON" : "OFF");
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
