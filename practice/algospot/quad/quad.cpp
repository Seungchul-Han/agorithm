#include <iostream>
#include <string>
using namespace std;

string solve(string& s, int& index)
{
    if (s[index] != 'x') return s.substr(index++, 1);

    string rs[4]; index++;
    for (int i=0; index < s.size() && i<4; ++i)
        rs[i] = solve(s, index);

    return 'x' + rs[2] + rs[3] + rs[0] + rs[1];
}

int main()
{
    int T;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        int index = 0;
        string ret;
        while(index < s.size()) {
            ret += solve(s, index);
        }
        cout << ret << endl;
    }
}
