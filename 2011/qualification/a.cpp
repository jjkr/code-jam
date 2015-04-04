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

#define range(i, N) for(int i=0; i<N; ++i)
#define rint(n) int n; cin >> n
#define rstr(s) string s; cin >> s

using namespace std;

void test_case(int case_num) {
    string s;
    getline(cin, s);
    istringstream ss(s);
    vector<pair<int, bool>> seq;
    vector<int> o;
    vector<int> b;

    while (ss.eof())
    {
        int n;
        ss >> n;
        char bot;
        ss >> bot;

        if (bot == 'O')
        {
            o.push_back(n);
            seq.push_back(make_pair(n, true));
        }
        else
        {
            b.push_back(n);
            seq.push_back(make_pair(n, false));
        }
    }

    auto oi = o.cbegin();
    auto bi = b.cbegin();
    auto opos = 0;
    auto bpos = 0;

    auto moves = 0;

    for (auto& i: seq)
    {
        auto diff = i.first - (i.second ? opos : bpos);
        if (i.second)
        {
        }
        else
        {
        }
    }

    cout << endl;
}

int main() {
    rint(num_cases);
    range(i, num_cases) {
        cout << "Case #" << i+1 << ": ";
        test_case(i);
    }
}
