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
    rint(L);
    set<pair<pair<int,int>, bool>> h,v;
    auto pos = make_pair(0, 0);
    enum direction {
        north,
        east,
        south,
        west
    };
    auto dir = north;
    int rl = 0;
    range(i, L) {
        rstr(S);
        rint(T);
        range(j, T) {
            for(auto c: S) {
                switch(c) {
                    case 'F':
                        if(dir == north) {
                            v.insert(make_pair(pos, true));
                        } else if(dir == south) {
                            pair<int, int> t(pos);
                            t.second -= 1;
                            v.insert(make_pair(t, false));
                        } else if(dir == east) {
                            h.insert(make_pair(pos, true));
                        } else if(dir == west) {
                            pair<int, int> t(pos);
                            t.second -= 1;
                            h.insert(make_pair(t, false));
                        }
                        switch(dir) {
                            case north:
                                pos.second += 1;
                                break;
                            case south:
                                pos.second -= 1;
                                break;
                            case east:
                                pos.first += 1;
                                break;
                            case west:
                                pos.first -= 1;
                                break;
                        }
                        break;
                    case 'L':
                        dir = (direction)(((int)dir - 1) % 4);
                        --rl;
                        break;
                    case 'R':
                        dir = (direction)(((int)dir + 1) % 4);
                        ++rl;
                        break;
                }
            }
        }
    }

    bool righthanded = rl > 0;
    for (auto l: v) {
        int best = 0;
        for_each(v.begin(), v.end(), [&](const pair<pair<int, int>, bool>& x) {
                if(x.first.second == l.first.second) {
                    int dist = l.first.first - x.first.first;
                    if (righthanded && dist && best ) {
                    }
                    if (!righthanded && !dist) {
                    }
                }
        });
        if (best != 0) {
            //cout << " l " << l.first << ", " << l.second << endl;
            //cout << " i " << i->first << ", " << i->second << endl;
            cout << "best " << best << endl;
        }
    }

}

int main() {
    rint(num_cases);
    range(i, num_cases) {
        cout << "Case #" << i+1 << ": ";
        test_case(i);
    }
}
