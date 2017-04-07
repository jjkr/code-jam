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
    auto N = ri();
    vector<int> v1(N);
    vector<int> v2(N);

    generate_n(v1.begin(), N, ri);
    generate_n(v2.begin(), N, ri);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    auto sum = 0ll;
    for (auto i = v1.begin(), j = v2.end() - 1; i != v1.end(); ++i, --j) {
        sum += (long long)(*i) * (*j);
    }

    cout << sum;
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
