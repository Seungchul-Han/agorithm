#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a < b) swap(a, b);
    return (a % b == 0) ? b : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a = 14, b = 21;

    cout << gcd(a, b) << endl;
    cout << gcd(b, a) << endl;
    cout << lcm(a, b) << endl;
    cout << lcm(b, a) << endl;

    a = 7; b = 8;
    cout << gcd(a, b) << endl;
    cout << gcd(b, a) << endl;
    cout << lcm(a, b) << endl;
    cout << lcm(b, a) << endl;
}
