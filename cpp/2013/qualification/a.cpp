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

int main() {
    rint(T);
    range(i, T) {
        vector<int> possible;
        int winner = -1;
        bool cheated = false;
        cout << "Case #" << i+1 << ": ";
        rint(row);
        range(j, (row-1)*4) {
            rint(tmp);
        }
        range(j, 4) {
            rint(val);
            possible.push_back(val);
        }
        range(j, (4-row)*4) {
            rint(tmp);
        }
        rint(row2);
        range(j, (row2-1)*4) {
            rint(tmp);
        }
        range(j, 4) {
            rint(val);
            if (find(possible.begin(), possible.end(), val) != possible.end()) {
                if (winner == -1) {
                    winner = val;
                } else {
                    cheated = true;
                }
            }
        }
        if (cheated) {
            cout << "Bad magician!" << endl;
        } else if (winner == -1) {
            cout << "Volunteer cheated!" << endl;
        } else {
            cout << winner << endl;
        }
    }
}
