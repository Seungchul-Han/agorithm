#include <iostream>
#include <cmath>

using namespace std;

int solve(double x, double y, double n)
{
    double ret = n + 2 * y * (atan(y/x) + atan(y/(n-x)));
    return (ret > (int)ret) ? (int)ret + 1 : (int)ret;
}

int main()
{
    int T;
    double x, y, n;
    cin >> T;
    while (T--) {
        cin >> x >> y >> n;
        cout << solve(x, y, n) << endl;
    }
}
