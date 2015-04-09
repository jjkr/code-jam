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

// read integer from cin
int ri()
{
    int i;
    cin >> i;
    return i;
}

void test_case(int case_num)
{
    auto firstRow = ri();
    int grid1[4][4];
    for (auto i = 0; i < 4; ++i)
    {
        for (auto j = 0; j < 4; ++j)
        {
            cin >> grid1[i][j];
        }
    }

    auto secondRow = ri();
    int grid2[4][4];
    for (auto i = 0; i < 4; ++i)
    {
        for (auto j = 0; j < 4; ++j)
        {
            cin >> grid2[i][j];
        }
    }

    vector<int> cards;
    for (auto i = 0; i < 4; ++i)
    {
        cards.push_back(grid1[firstRow-1][i]);
    }
    for (auto i = 0; i < 4; ++i)
    {
        cards.push_back(grid2[secondRow-1][i]);
    }

    sort(cards.begin(), cards.end());
    auto c = adjacent_find(cards.begin(), cards.end());
    if (c == cards.end())
    {
        cout << "Volunteer cheated!" << endl;
        return;
    }

    auto next = adjacent_find(++c, cards.end());
    if (next != cards.end())
    {
        cout << "Bad magician!" << endl;
        return;
    }

    cout << *c << endl;

}
}

int main()
{
    auto num_cases = ri();
    for (auto i = 0; i < num_cases; ++i)
    {
        cout << "Case #" << i+1 << ": ";
        test_case(i);
    }
}
