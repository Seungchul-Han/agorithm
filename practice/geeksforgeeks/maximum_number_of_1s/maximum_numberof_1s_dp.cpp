#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int psum[1005];
int inc[1005];      // filp includes index i
int ninc[1005];     // flip befor index i

void make_psum(string& s) {
    int bcount = 0, fcount = 0;
    for(int i=0; i < s.size(); ++i) {
        if (s[i] == '1')  bcount++;
        else fcount++;

        psum[i] = bcount;
    }
}

int bit_count(string& s, int i, int j) {
    if (i == 0) return psum[j];
    return psum[j]  - psum[i-1];
}

int solve(string& s) {
    inc[0] = (s[0] == '1') ? 0 : 1;
    ninc[0] = 0;

    for (int i = 1; i < s.size(); ++i) {
        int bit = (s[i] == '1') ? 1 : 0;
        int fbit = (bit - 1) * -1;

        inc[i] = max(inc[i-1] + fbit, bit_count(s, 0, i-1) + fbit);
        ninc[i] = max(inc[i-1] + bit, ninc[i-1] + bit);
    }
    return max(inc[s.size()-1], ninc[s.size()-1]);
}

int main() {
    int T = 0;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        make_psum(s);
        cout << solve(s) << endl;
    }
    return 0;
}
