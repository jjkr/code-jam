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

pair<int,int> mindels(const int root, set<pair<int, int>>& edges, set<int>& visited) {
    set<int> children;
    for_each(edges.begin(), edges.end(), [&](const pair<int, int> x) {
                if(x.first == root) {
                    children.insert(x.second);
                }
                if(x.second == root) {
                    children.insert(x.first);
                }
            });
    if(children.size() == 0) return make_pair(0,1);
    for_each(children.begin(), children.end(), [&](const int c) {
                cout << "root " << root << " child " << c << endl;
                auto m = mindels(c, edges);
            });
}

void test_case(int case_num) {
    map<int, int> nodes;
    set<pair<int, int>> edges;
    rint(N);
    range(i, N-1) {
        rint(x);
        rint(y);
        nodes[x] += 1;
        nodes[y] += 1;
        edges.insert(make_pair(x, y));
    }
    range(i, N) {
        set<int> visited;
        mindels(i+1, edges, visited);
    }
}

int main() {
    rint(num_cases);
    range(i, num_cases) {
        cout << "Case #" << i+1 << ": ";
        test_case(i);
    }
}
