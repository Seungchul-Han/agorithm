#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int fr[101][101];
int solve(int a, int b, int N)
{
    vector<int> infect(100, 0);
    queue<int> q;
    infect[a] = infect[b] = 2;
    q.push(a); q.push(b);

    int count = 2;
    while (!q.empty()) {
        int j = q.front();
        q.pop();
        for(int i=0;i<N;++i) {
            if (fr[j][i]==1) {
                infect[i]++;
                if (infect[i]==2) {
                    count++; q.push(i);
                }
            }
        }
    }
    return count;
}

int main()
{
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> fr[i][j];

        int Q, a, b;
        cin >> Q;
        while (Q--) {
            cin >> a >> b;
            cout << solve(a-1, b-1, N) << " ";
        }
        cout << endl;
    }
}
