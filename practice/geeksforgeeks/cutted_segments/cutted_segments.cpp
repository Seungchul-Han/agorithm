#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string.h>
using namespace std;

vector<int> dp;

int solve(int x, int y, int z, int length) {
    dp[0] = 0;
    //if (sl[0] < length)
    //    dp[sl[0]] = 1;

    for (int i = 1; i<=length; ++i) {
        if (x <= i) dp[i] = max(dp[i], dp[i - x] + 1);
        if (y <= i) dp[i] = max(dp[i], dp[i - y] + 1);
        if (z <= i) dp[i] = max(dp[i], dp[i - z] + 1);
    }
    return dp[length];
}

int main() {
    int T = 0;
    int N = 0;
    cin >> T;
    while (T--) {
        int x, y, z;
        cin >> N;
        cin >> x >> y >> z;
        dp.resize(N + 1, numeric_limits<int>::min());
        cout << solve(x, y, z, N) << endl;
    }
}
