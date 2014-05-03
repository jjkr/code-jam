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

void xors(const string& a, string& b) {
    range(i, a.length()) {
        if(a.at(i) == '1') {
            if(b[i] == '1') {
                b[i] = '0';
            } else {
                b[i] = '1';
            }
        }
    }
}

int f(vector<string>& devices, vector<string>& outlets) {
    for(auto d: devices) {
        for(auto o: outlets) {
            auto t = o;
            xors(d, t);
            for(auto d2: devices) {
                if(find_if(o.begin(), o.end(), [=](const string& s) -> bool {
                            xors(s, d2);
                            });
            }
        }
    }
}

void test_case(int case_num) {
    rint(N);
    rint(L);
    cout << "N " << N << endl;
    vector<string> outlets;
    vector<string> devices;
    range(j, N) {
        rstr(outlet);
        cout << "r outlet " << outlet << endl;
        outlets.push_back(outlet);
    }
    range(j, N) {
        rstr(dev);
        devices.push_back(dev);
    }
    f(devices, outlets);
    cout << endl;
}

int main() {
    rint(num_cases);
    range(i, num_cases) {
        cout << "Case #" << i+1 << ": ";
        test_case(i);
    }
}
