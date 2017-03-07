#include <iostream>
#include <vector>
#include <bitset>
#include <limits>
#include <string.h>
using namespace std;

int T, N;
constexpr int X = 15;
constexpr int Y = 1 << X;
vector<vector<double> > dist;
double dp[Y][X];

void read()
{
    dist.clear();
    dist.resize(N);
    for (int i = 0; i < N; ++i) {
        dist[i].resize(N);
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }
}

double visit(int i, int S)
{
    double& ret = dp[S][i];
    if (ret != 0) return ret;

    for (int j = 0; j < N; ++j) {
        if (S == (1 << j)) {
            ret = dist[i][j];
            return ret;
        }
    }

    double sub = numeric_limits<double>::max();
    for (int j = 0; j < N; ++j) {
        if (S & (1 << j)) {
            sub = min(sub, dist[i][j] + visit(j, S & ~(1 << j)));
        }
    }
    ret = sub;

    return ret;
}

double solve()
{
    memset(dp, 0, sizeof(dp));
    int S = (1 << N) - 1;
    double ret = numeric_limits<double>::max();
    for (int i = 0; i < N; ++i) {
        ret = min(ret, visit(i, S & ~(1 << i)));
    }
    return ret;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> N;
        read();
        cout.precision(10);
        cout << fixed << solve() << endl;
    }
    return 0;
}

