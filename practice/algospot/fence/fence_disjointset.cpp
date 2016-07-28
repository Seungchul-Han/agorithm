#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
    public:
        vector<int> parent;
        vector<int> rank;
        vector<int> count;

        DisjointSet(int n) : parent(n), rank(n,1), count(n,1) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if (u == parent[u]) return u;
            return parent[u] = find(parent[u]);
        }

        void merge(int u, int v) {
            u = find(u);
            v = find(v);
            if (u == v) return;
            if (rank[u] > rank[v]) swap(u, v);
            parent[u] = v;
            if (rank[u] == rank[v]) ++rank[v];
            count[u] += count[v];
            count[v] = count[u];
        }

        int getCount(int u) { u = find(u); return count[u]; }
};

int T = 0;
int N = 0;

void input(vector<int>& h, vector<pair<int, int>>& hp)
{
    for (int i=0; i<N; ++i) {
        cin >> h[i];
        hp.push_back(make_pair(h[i], i));
    }
}

int solve(vector<int>& h, vector<pair<int, int>>& hp)
{
    int ans = 0;
    sort(hp.begin(), hp.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return (a.first > b.first); });
    DisjointSet djset(h.size());
    for (auto& i : hp) {
        if (i.second < h.size() - 1 && h[i.second] <= h[i.second+1]) {
            djset.merge(i.second, i.second+1);
            //cout << i.second << " + " << i.second + 1 << " : " << djset.getCount(i.second) * i.first << endl;
        }
        if (i.second > 0 && h[i.second] < h[i.second-1]) {
            djset.merge(i.second, i.second-1);
            //cout << i.second << " + " << i.second - 1 << " : " << djset.getCount(i.second) * i.first << endl;
        }
        ans = max(ans, djset.getCount(i.second) * i.first);
    }
    return ans;
}


int main()
{
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> h(N);
        vector<pair<int, int>> hp;
        input(h, hp);
        cout << solve(h, hp) << endl;
    }
}
