#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int solve(vector<int>& value, vector<int>& point, int n, int m)
{
    dp[0] = 0;
    for (int i=1; i<=m; ++i) {
        for (int j=0; j<n; ++j) {
            if (i >= value[j]) {
                dp[i] = max(dp[i], dp[i-value[j]] + point[j]);
            }
        }
    }
    return dp[m];
}

int main()
{
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        m /= 100;
        vector<int> value(n);
        vector<int> point(n);
        for (int i=0; i<n; ++i) {
            cin >> value[i] >> point[i];
            value[i] /= 100;
        }
        dp.clear(); dp.resize(m+1);
        cout << solve(value, point, n, m) << endl;
    }
}
