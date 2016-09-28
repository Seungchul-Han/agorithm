#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void calc(int& ch, int& wd, int& sum)
{
    if (ch > 0) {
        wd++;
        sum += ch;
//        cout << "ch : " << ch << ", wd : " << wd << ", sum : " << sum << endl;
        ch = 0;
    }
}

double solve(vector<string>& s)
{
    int sum = 0, ch = 0, wd = 0;

    for (auto& line : s) {
        for (int i = 0; i < line.size(); ++i) {
            if (isalpha(line[i])) ch++;
            else if (i > 0 && isalpha(line[i-1]) && line[i] == '-' && i == line.size() -1) break;
            else calc(ch, wd, sum);
        }
        if (line[line.size()-1] != '-' && ch > 0) calc(ch, wd, sum);
    }
    calc(ch, wd, sum);
    return (double)sum/(double)wd;
}

int main()
{
    int T, N; cin >> T;
    cout << fixed;
    cout.precision(3);

    while (T--) {
        cin >> N;
        string k; getline(cin, k);
        vector<string> s(N);
        for (int i=0; i<N; ++i) {
            getline(cin, s[i]);
        }
        cout << solve(s) << endl;
    }
}
