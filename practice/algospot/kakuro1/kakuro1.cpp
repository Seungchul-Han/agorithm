#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string.h>

using namespace std;
using Hint = vector<tuple<int, int, int, int>>;
Hint hint;
int input[20][20];
int check[20][20];
int T, N;

enum {
    DIRECTION = 0,
    Y,
    X,
    SUM
};

void printProblem()
{
    cout << T << endl;
    cout << N << endl;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x)
            cout << check[y][x] << " ";
        cout << endl;
    }

    sort(begin(hint), end(hint));
    for (auto& t : hint) {
        cout << get<Y>(t) << " ";
        cout << get<X>(t) << " ";
        cout << get<DIRECTION>(t) << " ";
        cout << get<SUM>(t) << endl;
    }
}

void findX(int y, int x)
{
    int sum = 0;
    for (int i = x + 1; i < N; ++i) {
        if (input[y][i] == 0 || check[y][i] & 1) break;
        sum += input[y][i];
        check[y][i] |= 1;
    }
    if (sum != 0) {
        hint.push_back(make_tuple(0, y + 1, x + 1, sum));
    }
}

void findY(int y, int x)
{
    int sum = 0;
    for (int i = y + 1; i < N; ++i) {
        if (input[i][x] == 0 || check[i][x] & 2) break;
        sum += input[i][x];
        check[i][x] |= 2;
    }
    if (sum != 0) {
        hint.push_back(make_tuple(1, y + 1, x + 1, sum));
    }
}
void solve()
{
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (input[y][x] == 0) {
                findX(y, x);
                findY(y, x);
            }
        }
    }

    printProblem();
}

int main()
{
    cin >> T;
    int test = T;
    while (test--) {
        cin >> N;
        memset(input, 0, sizeof(input));
        memset(check, 0, sizeof(check));
        hint.clear();
        for (int y = 0; y < N; ++y)
            for (int x = 0; x < N; ++x)
                cin >> input[y][x];

        solve();
    }
}
