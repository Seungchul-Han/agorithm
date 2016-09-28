#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> height, counts, checked;
vector<pair<int, int>> pan; // height, index
int maax;

void make_sort_pan(vector<pair<int, int>>& pan, vector<int>& height)
{
    pan.clear();
    for (int i=0; i<height.size(); ++i)
        pan.push_back(make_pair(height[i], i));
    sort(begin(pan), end(pan), greater<pair<int, int>>());
}

void update(int idx)
{
    int S = 0, E = height.size() - 1;
    int l_end = idx == S ? S : (checked[idx - 1] ? idx - counts[idx - 1] : idx);
    int r_end = idx == E ? E : (checked[idx + 1] ? idx + counts[idx + 1] : idx);

    counts[l_end] = counts[r_end] = r_end - l_end + 1;
    checked[idx] = 1;
    maax = max(maax, counts[l_end] * height[idx]);
}

int solve(vector<int>& input)
{
    height = input;
    counts.clear(); counts.resize(height.size(), 1);
    checked.clear(); checked.resize(height.size(), 0);
    make_sort_pan(pan, height);
    maax = pan[0].first;
    checked[pan[0].second] = 1;

    for (int i = 1; i < pan.size(); i++)
        update(pan[i].second);

    return maax;
}

int main()
{
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        height.resize(N, 0);
        for (int i=0; i<N; ++i) cin >> height[i];
        cout << solve(height) << endl;
    }
}
