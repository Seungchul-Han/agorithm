#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        int findKthNum(int num, int n, int& k) {
//            cout << "findkth: " << num << " " << k << endl;
            if (k == 0)
                return num;

            num *= 10;
            for (int i = 0; i < 10; ++i, ++num) {
                if (num <= n) {
                    int ret = findKthNum(num, n, --k);
                    if (k == 0)
                        return ret;
                }
                else
                    break;
            }
        }

        int findKthNumber(int n, int k) {
            for (int i = 1; i < 10; ++i) {
                if (i <= n) {
                    int num = findKthNum(i, n , --k);
                    if (k == 0) {
                        return num;
                    }
                }
            }
            return 0;
        }
};


int main()
{
    Solution s;
    cout << s.findKthNumber(681692778, 351251360) << endl;
    return 0;
}
