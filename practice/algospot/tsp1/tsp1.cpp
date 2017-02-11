#include <iostream>
#include <vector>
#include <bitset>
#include <limits>
using namespace std;

double sum;
double ret;
int T;
int N;
vector<vector<double>> dist;
bitset<8> vcheck;

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

void visit(int from)
{
    if (vcheck.count() == N) {
        ret = min(ret, sum);
        return;
    }
    
    for (int to = 0; to < N; ++to) {
        if (from == to || vcheck.test(to)) continue;
        vcheck.set(to); sum += dist[from][to];
        visit(to);
        vcheck.reset(to); sum -= dist[from][to];
    }
}

double solve() {
    vcheck.reset();
    sum = 0;
    ret = numeric_limits<double>::max();
    for (int from = 0; from < N; ++from) {
        vcheck.set(from);
        visit(from);
        vcheck.reset(from);
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
