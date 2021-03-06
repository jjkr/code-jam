#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
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
auto rc() { return read<char>(); };
auto ri() { return read<int>(); };
auto rd() { return read<double>(); };
auto rs() { return read<string>(); };

void test_case(int case_num)
{
    auto R = ri();
    auto C = ri();

    cout << endl;

    vector<vector<char>> grid;
    for (auto i = 0; i < R; ++i) {
        grid.push_back(vector<char>());
        for (auto j = 0; j < C; ++j) {
            grid[i].push_back(rc());
        }
    }

    for (auto i = 0; i < R; ++i) {
        for (auto j = 0; j < C; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
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
