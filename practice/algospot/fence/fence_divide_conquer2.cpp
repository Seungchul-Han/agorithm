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

int getNext(vector<int>& h, int s, int e, int i, int j)
{
    if (i-1 < s && j+1 >= e) return -1;
    else if (i-1 < s) return j+1;
    else if (j+1>= e) return i-1;

    int left = (i-1) > s ? h[i-1] : -1;
    int right = (j+1) < e ?  h[j+1] : -1;

    return (left > right) ? i-1 : j+1;
}

int calcWidth(vector<int>& h, int s, int e, int mid)
{
    if (s == e) return 0;

    int height = h[mid];
    int count = 1;
    int width = height * count;

    int i = mid;
    int j = mid;
    int index = getNext(h, s, e, i, j);

    while (count < e - s) {
        count++;
        height = min(height, h[index]);
        width = max(width, count * height);
        i = min(i, index);
        j = max(j, index);
        index = getNext(h, s, e, i, j);
        cout << "left : " << i << " right : " << j << " height : " << height << " width : " << count * height << endl;
     }

     return width;
}

int solve(vector<int>& h, int s, int e)
{
    if (s == e-1) return h[s];

    int ans = 0;
    int mid = (e + s) / 2;
    ans = max(ans, solve(h, s, mid));
    ans = max(ans, solve(h, mid, e));
    ans = max(ans, calcWidth(h, s, e, mid));

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
