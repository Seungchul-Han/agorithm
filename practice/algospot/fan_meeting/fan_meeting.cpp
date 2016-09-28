#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            c[i + j] += a[i] * b[j];
    return c;
}

vector<int>& operator+(vector<int>& a, vector<int>& b)
{
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); ++i) a[i] += b[i];
    return a;
}

vector<int>& operator-(vector<int>& a, vector<int>& b)
{
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); ++i) a[i] -= b[i];
    return a;
}

vector<int> karatsuba(vector<int>& a, vector<int>& b)
{
    if (a.empty() || b.empty()) return vector<int>();
    if (a.size() < b.size()) return karatsuba(b, a);
    if (a.size() <= 50) return multiply(a, b);

    int m = (a.size() / 2);
    vector<int> a1(begin(a), begin(a) + m);
    vector<int> a0(begin(a) + m, end(a));
    vector<int> b1(begin(b), begin(b) + min<int>(b.size(), m));
    vector<int> b0(begin(b) + min<int>(b.size(), m), end(b));

    vector<int> z0 = karatsuba(a1, b1);
    vector<int> z2 = karatsuba(a0, b0);
    vector<int> z1 = karatsuba(a1 + a0, b1 + b0);
    z1 - z0 - z2;

    vector<int> ret(begin(z0), end(z0));
    ret.resize(max(m + z1.size(), ret.size()));
    for (int i = 0; i < z1.size(); ++i) ret[m+i] += z1[i];
    ret.resize(max(2 * m + z2.size(), ret.size()));
    for (int i = 0; i < z2.size(); ++i) ret[2*m+i] += z2[i];

    return ret;
}

int solve(string& mem, string& fan)
{
    vector<int> m(mem.size()), f(fan.size());
    for (int i = 0; i < mem.size(); ++i) m[i] = (mem[mem.size() - i - 1] == 'M') ? 1 : 0;
    for (int i = 0; i < fan.size(); ++i) f[i] = (fan[i] == 'M') ? 1 : 0;

    int count = 0;
    vector<int> ret = karatsuba(f, m);
    for (int i = m.size()-1; i < f.size(); ++i) {
        if (ret[i] == 0) count++;
    }
    return count;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        string mem, fan;
        cin >> mem >> fan;
        cout << solve(mem, fan) << endl;
    }
}
