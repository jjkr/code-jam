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
    rint(N);
    vector<string> strs;
    range(i, N) {
        rstr(s);
        strs.push_back(s);
    }
    map<int, int> pos;
    map<int, int> counts;
    range(i, strs.size()) {
        pos[i] = 0;
    }
    int edits = 0;
    while(true) {
        //cout << "LOOP" << endl;
        int min = 0x7fffffff;
        int max = 0;
        char first = strs[0].at(pos[0]);
        //cout << "first " << first << endl;
        range(i, strs.size()) {
            //cout << "s " << strs[i] << endl;
            //cout << "pos " << pos[i] << endl;
            if(strs[i].at(pos[i]) != first) {
                cout << "Fegla won" << endl;
                return;
            }
            int count = 0;
            int p = pos[i];
            int l = strs[i].length();
            //cout << "p " << p << endl;
            for(int j= p; j<l; ++j) {
                if(strs[i].at(j) == first) {
                    ++count;
                } else {
                    break;
                }
            }
            counts[i] = count;
            pos[i] = pos[i] + count;
            if(count < min) {
                min = count;
            }
            if(count > max) {
                max = count;
            }
        }
        bool end = pos[0] == strs[0].length();
        range(i, pos.size()) {
            end = end || pos[i] == strs[i].length();
        }
        //cout << "min " << min << endl;
        //cout << "max " << max << endl;
        
        if( min == max && !end ) {
            //cout << "minmax " << endl;
            continue;
        }
        int sum=0;
        for(auto c: counts) {
            sum+= c.second;
        }
        //cout << "sum " << sum << endl;
        int avg = (sum+0.5f)/counts.size();
        //cout << "avg " << avg << endl;
        for(auto c: counts) {
            int d = avg-c.second;
            if(d<0)d=-d;
            edits+=d;
        }

        for(auto p: pos) {
            if (p.second == strs[p.first].length() && !end) {
                cout << "Fegla won" << endl;
                return;
            }
            if (p.second != strs[p.first].length() && end) {
                cout << "Fegla won" << endl;
                return;
            }
        }
        if(end) {
            break;
        }

    }
    cout << edits << endl;
}

int main() {
    rint(num_cases);
    range(i, num_cases) {
        cout << "Case #" << i+1 << ": ";
        test_case(i);
    }
}
