#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
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

using namespace std;

namespace
{
template <typename T>
auto read()
{
    T i;
    cin >> i;
    return i;
}
auto rc() { return read<char>(); };
auto ri() { return read<int>(); };
auto rd() { return read<double>(); };
auto rs() { return read<string>(); };

void test_case(int case_num)
{
    char board[4][4];

    auto boardFull = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            board[i][j] = rc();
        }
    }

    for (int i = 0; i < 4; ++i) {
        auto cur = 'N';
        for (int j = 0; j < 4; ++j) {
            auto c = board[i][j];

            //cout << "boardFull: " << boardFull << " c: " << c << endl;
            if (c == '.') {
                boardFull = false;
            }

            if (c == 'T') {
                continue;
            } else if (cur == 'N') {
                cur = c;
                continue;
            } else if (cur != c) {
                cur = 'D';
            }

        }

        if (cur == 'X') {
            cout << "X won";
            return;
        } else if (cur == 'O') {
            cout << "O won";
            return;
        }
    }

    for (int i = 0; i < 4; ++i) {
        auto cur = 'N';
        for (int j = 0; j < 4; ++j) {
            auto c = board[j][i];
            if (c == 'T') {
                continue;
            } else if (cur == 'N') {
                cur = c;
                continue;
            } else if (cur != c) {
                cur = 'D';
            }
        }

        if (cur == 'X') {
            cout << "X won";
            return;
        } else if (cur == 'O') {
            cout << "O won";
            return;
        }
    }

    auto cur = 'N';
    for (int i = 0; i < 4; ++i) {
        auto c = board[i][i];
        if (c == 'T') {
            continue;
        } else if (cur == 'N') {
            cur = c;
            continue;
        } else if (cur != c) {
            cur = 'D';
        }
    }
    if (cur == 'X') {
        cout << "X won";
        return;
    } else if (cur == 'O') {
        cout << "O won";
        return;
    }

    cur = 'N';
    for (int i = 0; i < 4; ++i) {
        auto c = board[i][3-i];
        //cout << "c " << c;
        if (c == 'T') {
            continue;
        } else if (cur == 'N') {
            cur = c;
            continue;
        } else if (cur != c) {
            cur = 'D';
        }
    }
    if (cur == 'X') {
        cout << "X won";
        return;
    } else if (cur == 'O') {
        cout << "O won";
        return;
    }

    if (boardFull) {
        cout << "Draw";
    } else {
        cout << "Game has not completed";
    }
}
}

int main()
{
    auto num_cases = ri();
    cout << fixed << setprecision(7);
    for (auto i = 0; i < num_cases; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        test_case(i);
        cout << endl;
    }
}
