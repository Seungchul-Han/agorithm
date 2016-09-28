#include <iostream>
#include <string.h>
using namespace std;

int dp[101][501];
int m =  1000000007;
int T, N, K;
int result = 0;

int solve(int i, int j)
{
    cout << "  ";
    cout << i << " " <<  j  << "  " << endl;
    if (i == 0 && j == 0) return dp[0][0] = 0;
    if (i == 1) return dp[i][j] = 1;

    int& ret = dp[i][j];
    if (ret != -1) return ret;

    ret = solve(i-1, j);
    cout << i - 1 << "  " << j << endl;
    for (int p = i+1; p < N; p++) {
        int jj  = (j >= i-1 ) ? j - i : N - i-1 + j;
        //ret += solve(p, jj) % m;
        cout << p << "  " << jj << endl;
    }
    return ret;
}


int main()
{
    cin >> T;
    while (T--) {
        cin >> N >> K;
        cout << N << "  " << K << endl;
        memset(dp, -1, sizeof(dp));
        cout << solve(K, 0) << endl;

        for (int i = 0; i <= K; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << dp[i][j] << "  ";
            }
            cout  << endl;
        }
    }
}
