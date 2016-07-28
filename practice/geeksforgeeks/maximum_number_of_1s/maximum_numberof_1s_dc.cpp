#include <iostream>
#include <string>
#include <limits>
#include <string.h>
using namespace std;
int temp[1005];
int count = 0;
void make_temp(string& s)
{
    memset(temp, 0, sizeof(temp));
    count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            count++;
            temp[i] = -1;
        }
        else
            temp[i] = 1;
    }
}

int solve(int i, int j)
{
    if (j == i + 1) {
        return temp[i];
    }

    int mid = (i + j) / 2;
    int ans = max(solve(i, mid), solve(mid, j));

    int k = mid;
    int sum = 0;
    int left = numeric_limits<int>::min();
    int right = left;
    while (k < j) {
        sum += temp[k]; k++;
        right = max(right, sum);
    }
    k = mid - 1;
    sum = 0;
    while (k >= 0) {
        sum += temp[k]; k--;
        left = max(left, sum);
    }
    ans = max(ans, left+right);
    return ans;
}

int main() {
    int T = 0;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        make_temp(s);
        //for (auto a : temp) cout << a << " ";
        //cout << endl;
        cout << count + solve(0, s.size()) << endl;
    }
    return 0;
}
