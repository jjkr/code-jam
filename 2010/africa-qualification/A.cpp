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
auto ri() { return read<int>(); };
auto rd() { return read<double>(); };
auto rs() { return read<string>(); };

void test_case(int case_num)
{
    auto C = ri();
    auto I = ri(); //number of items

    auto v = vector<int>();
    for (auto i = 0; i < I; ++i) {
        v.push_back(ri());
    }
    vector<int> orig = v;

    sort(v.begin(), v.end());
    //cout << '[';
    //for (auto i = v.begin(); i != v.end(); ++i) {
    //    cout << *i << ", ";
    //}

    auto lo = 0;
    auto hi = v.size();

    for (auto i = v.begin(); i != v.end() - 1; ++i) {
        //cout << endl;
        auto diff = C - (*i);
        //cout << "x = " << (*i) << " i " << distance(v.begin(), i) << " diff " << diff << endl;
        auto other = lower_bound(i + 1, v.end(), C - *i);
        if (*other + *i == C) {
            //cout << "count " << C << endl;
            //cout << *i << " + " << *other << endl;
            if(*i == *other) {
                auto ans1 = distance(orig.begin(), find(orig.begin(), orig.end(), *i)) + 1;
                auto ans2 = distance(orig.begin(), find(orig.begin(), orig.end(), *other)) + 2;
                cout << min(ans1, ans2) << " " << max(ans1, ans2);
            } else {
                auto ans1 = distance(orig.begin(), find(orig.begin(), orig.end(), *other)) + 1;
                auto ans2 = distance(orig.begin(), find(orig.begin(), orig.end(), *i)) + 1;
                cout << min(ans1, ans2) << " " << max(ans1, ans2);
            }
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
