#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string.h>
using namespace std;

vector<int> dp;

int solve(vector<int>& sl, int length) {
    dp[0] = 0;
    if (sl[0] < length)
        dp[sl[0]] = 1;

    for (int i=sl[0] + 1; i<=length; ++i) {
        for (int j=0; j<sl.size(); ++j) {
            if (sl[j] <= i) {
//                cout <<i << ", " << j << ", (" << i << " -  "<< sl[j] << ") : " << dp[i - sl[j]] <<  " = ";
                dp[i] = max(dp[i], dp[i - sl[j]] + 1);
            }

 /*           for (int k=0; k <= length; ++k) {
                int a = (dp[k] == numeric_limits<int>::min()) ? -2 : dp[k];
                cout << a << " ";
            }
            cout << endl;
*/        }
    }
    return dp[length];
}

int main() {
    int T = 0;
    int N = 0;
    cin >> T;
    while (T--) {
        vector<int> sl(3, 0);
        cin >> N;
        cin >> sl[0] >> sl[1] >> sl[2];
        sort(begin(sl), end(sl));
        dp.resize(4001, numeric_limits<int>::min());
        cout << solve(sl, N) << endl;
    }
}
