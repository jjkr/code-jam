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
    rint(A);
    rint(B);
    rint(K);
    if(A>B) swap(A,B);
    int count = 0;
    range(i, A) {
        if(i<K) {
            count += B;
            continue;
        }
        range(j, B) {
            if((j&i)<K) ++count;
        }
    }
    cout << count << endl;
}

int main() {
    rint(num_cases);
    range(i, num_cases) {
        cout << "Case #" << i+1 << ": ";
        test_case(i);
    }
}
