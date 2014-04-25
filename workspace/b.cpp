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

enum direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

void test_case(int case_num) {
    rint(R);
    rint(C);

    map<pair<int,int>,int> game;
    pair<int,int> current(-1,-1);
    range(i, R){
        rstr(line);
        vector<int> chars;
        range(j, line.size()) {
            int c = line.at(j);
            if (c=='O') {
                current.first = i;
                current.second = chars.size()-1;
                cout << "start" << current.first << ", " << current.second << endl;
                game[make_pair(i,j)] = c;
            }
        }
    }
    vector<pair<int,int>> poss;
    poss.push_back(current);
    map<pair<int,int>,direction> portals;

    bool cake = false;
    while (!cake) {
        range(i,4) {
            pair<int,int> x;
            switch(i){
                case 0:
                    x.first = 0;
                    x.second = 1;
                    break;
                case 1:
                    x.first = 1;
                    x.second = 0;
                    break;
                case 2:
                    x.first = 0;
                    x.second = -1;
                    break;
                case 3:
                    x.first = -1;
                    x.second = 0;
                    break;
            }
            while(x.first>0 && x.first<C) {
            }
        }
    }
}

int main() {
    rint(num_cases);
    range(i, num_cases) {
        cout << "Case #" << i+1 << ": ";
        test_case(i);
        cout << endl;
    }
}
