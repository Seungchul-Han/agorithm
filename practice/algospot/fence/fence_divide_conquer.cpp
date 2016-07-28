#include <iostream>
#include <vector>

using namespace std;

int T = 0;
int N = 0;

void input(vector<int>& h)
{
    for (int i=0; i<N; ++i) {
        cin >> h[i];
    }
}

int solve(vector<int>& h, int s, int e)
{
    if (s == e-1) return h[s];

    int mid = (e + s) / 2;
    int ans = max(solve(h, s, mid), solve(h, mid, e));
    int left = mid-1;
    int right = mid;
    int height = min(h[left], h[right]);
    ans = max(ans, 2 * height);
    while (s < left || right < e-1) {

        //        cout << "ss left : " << left << " right : " << right << " height : " << h[left-1] << " " << h[right] << endl;
        if (right < e-1 && (left == s || h[left-1] < h[right+1])) {
            ++right;
            height = min(height, h[right]);
        }
        else {
            --left;
            height = min(height, h[left]);
        }
        //cout << "left : " << left << " right : " << right << " height : " << height << " width : " << (right-left) * height << endl;
        ans = max(ans, (right-left+1) * height);
    }

    return ans;
}


int main()
{
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> h(N);
        input(h);
        cout << solve(h, 0, h.size()) << endl;
    }
}

