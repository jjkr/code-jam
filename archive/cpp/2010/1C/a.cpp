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
#define rstr(n) string s; cin >> n

using namespace std;

void test(int case_num) {
    rint(N);
    vector<pair<int,int>> wires;
    range(i, N) {
        rint(A);
        rint(B);
        wires.push_back(make_pair(A, B));
    }
    int c = 0;
    for (auto w : wires) {
        c += count_if(wires.begin(), wires.end(), [=](pair<int, int> x) { return x.first < w.first && x.second > w.second; });
    }
    cout << c << endl;
}

int main() {
    rint(num_cases);
    range(i, num_cases) {
        cout << "Case #" << i+1 << ": ";
        test(i);
    }
}

