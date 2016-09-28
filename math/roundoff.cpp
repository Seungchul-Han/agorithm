#include <iostream>
#include <cmath>
using namespace std;

double round(double value, int pos)
{
    double temp;
    temp = value * pow(10, pos);
    temp = floor(temp + 0.5);
    temp *= pow(10, -pos);
    return temp;
}

int main()
{
    double num1 = 0.987654321;

    for (int i = 0; i < 10; ++i)
        cout << i << " : " << round(num1, i) << endl;
}
