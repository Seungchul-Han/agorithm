#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<string>& depot, int count, int n, int m)
{
    if (depot.empty()) {
        cout << "NO" << endl;
        return;
    }

    int i = 0, j = 0;
    int wall = 0;

    int row = -1, column = -1;
    for (i = 0; i < n; ++i) {
        j = find(begin(depot[i]), end(depot[i]), '*') - begin(depot[i]);
        if (j != m) break;
    }

    //cout << i <<", " << j << endl;
    if (i < n && j < m) {
        column  = j;
        while (i < n) {
            if (depot[i][j] == '*') wall++;
            if (row == -1 && j + 1 < m && depot[i][j+1] == '*') {
                row = i;
                for (int k = j+1; k < m; ++k) {
                    if (depot[i][k] == '*') wall++;
                    else break;
                }
            }
            if ((row == -1 || row == i) && j - 1 > 0 && depot[i][j-1] == '*') {
                row = i;
                for (int k = j-1; k >= 0; k--) {
                    if (depot[i][k] == '*') wall++;
                    else break;
                }
            }
            i++;
        }
    }
    if (count == wall) cout << "YES" << endl << row + 1 << " " << column + 1 << endl;
    else cout << "NO" << endl;
}

int main()
{
    vector<string> depot;
    int n, m, count = 0;
    cin >> n >> m;
    depot.resize(n);
    for (int i=0; i<n; ++i) {
        cin >> depot[i];
        for (int j=0; j<m; ++j)
            if (depot[i][j]=='*') count++;
    }

    solve(depot, count, n, m);

}
