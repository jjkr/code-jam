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
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define RANGE(i, N) for(int i=0; i<N; ++i)
#define FOR_EACH(c, f) for_each(c.begin(), c.end(), f)
#define rint(n) int n; cin >> n
#define rstr(n) string s; cin >> n

using namespace std;

int main() {
    rint(num_cases);
    RANGE(i, num_cases) {
        cout << "Case #" << i+1 << ": ";
        rint(nblocks);
        vector<double> naomi(nblocks);
        vector<double> ken(nblocks);
        RANGE(j, nblocks) {
            cin >> naomi[j];
        }
        RANGE(j, nblocks) {
            cin >> ken[j];
        }
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        vector<double> ncpy(naomi);
        int points = 0;
        for (auto b: ken) {
            auto f = find_if(naomi.begin(), naomi.end(), [=](double n) { return n > b; });
            if (f == naomi.end()) {
                break;
            } else {
                naomi.erase(f);
                ++points;
            }
        }
        cout << points << " ";
        points = 0;
        int k = 0;
        RANGE(j, ncpy.size()) {
            if (k > ncpy.size()-1) {
                break;
            }
            while (ncpy[j] > ken[k]) {
                ++points;
                ++k;
                if (k > ncpy.size()-1) {
                    break;
                }
            }
            ++k;
        }
        cout << points << endl;
    }
}
