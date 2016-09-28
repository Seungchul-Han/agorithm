#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void normalize(vector<int>& num) {
    num.push_back(0);
    for (int i = 0; i < num.size(); i++) {
        if (num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else if (num[i] > 0) {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    if (num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    normalize(c);
    return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++) a[i + k] += b[i];
    normalize(a);
}

void subFrom(vector<int>& a, const vector<int>& b) {
    a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < b.size(); i++) a[i] -= b[i];
    normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    if (an < bn) return karatsuba(b, a);
    if (an == 0 || bn == 0) return vector<int>();
    if (an <= 50) return multiply(a, b);
    //if (an == 1 && bn == 1) return vector<int>(1, a[0]*b[0]);

    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    vector<int> z0 = karatsuba(a0, b0);
    vector<int> z2 = karatsuba(a1, b1);
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);
    return ret;
}

string toString(vector<int> a) {
    string ret;
    while (a.size() > 1 && a.back() == 0) a.pop_back();
    for (int i = 0; i < a.size(); i++)
        ret += char('0' + a[a.size() - 1 - i]);
    return ret;
}

vector<int> fromString(const string& s) {
    vector<int> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(s[i] - '0');
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    vector<int> a = fromString("1934111111111111111112222222222222222233333333333333333333444444444444555555555555555");
    vector<int> b = fromString("2");
    cout << toString(karatsuba(a, b)) << endl;
}
