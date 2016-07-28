#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int dp[100][101];

int solve(vector<int>& v, vector<int>& w, int W)
{
    for (int j=1; j<=W; ++j) {
        if (w[0] <= j) {
            dp[0][j] = v[0];
        }
   }
   for (int i=1; i<v.size(); ++i) {
        for (int j=1; j<=W; ++j) {
            if (w[i]<=j) {
                dp[i][j] = max(dp[i-1][j-w[i]] + v[i], dp[i-1][j]);
//                cout << i << ", " << j << " : " << dp[i][j] << endl;
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    for (int a=0; a < v.size(); ++a) {
        for (int b = 0; b <= W; ++b) {
           cout << dp[a][b] << "  ";
        }
        cout << endl;
    }
    return dp[v.size()-1][W];
}

int main()
{
    int T, N, W;
    cin >> T;
    while (T--) {
        cin >> N >> W;
        vector<int> v(N);
        vector<int> w(N);
        for (int i=0; i<N; ++i) cin >> v[i];
        for (int i=0; i<N; ++i) cin >> w[i];
        memset(dp, 0, sizeof(dp));
//    for (int a=0; a < v.size(); ++a) {
//        for (int b = 0; b <= W; ++b) {
//            cout << dp[a][b] << "  ";
//        }
//        cout << endl;
//    }
        cout << solve(v, w, W) << endl;
    }

    return 0;
}
