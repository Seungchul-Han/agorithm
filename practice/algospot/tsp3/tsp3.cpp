#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>
using namespace std;

int T;
int N;
double ret;
vector<vector<double>> dist;
vector<pair<double, pair<int, int> > > edges;

constexpr int MAX = 20;
constexpr int DEPTH = 12;
map<int, double> cache[MAX][DEPTH + 1];

void read()
{
    dist.clear();
    dist.resize(N);
    edges.clear();
    for (int i = 0; i < N; ++i) {
        dist[i].resize(N);
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
            if (i < j) {
                edges.push_back(make_pair(dist[i][j], make_pair(i, j)));
                sort(begin(edges), end(edges));
            }
        }
    }
}

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

        bool merge(int u, int v) {
            u = find(u);
            v = find(v);
            if (u == v) return false;
            // low tree shoud be merged under the high tree
            if (rank[u] > rank[v]) swap(u, v);
            parent[u] = v;
            // if heights are equal, parent tree height + 1
            if (rank[u] == rank[v]) ++rank[v];
            count[u] += count[v];
            count[v] = count[u];
            return true;
        }
};


double mst(int from, int visited)
{
    DisjointSet sets(N);
    double sum = 0;
    for (int i = 0; i < edges.size(); ++ i) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (u != from && (visited & 1 << u)) continue;
        if (v != from && (visited & 1 << v)) continue;
        if (sets.merge(u, v))
            sum += edges[i].first;
    }
    return sum;
}

double dp(int from, int vcheck)
{
    if (vcheck == (1 << N) - 1)
        return 0;

    int remaining = N - __builtin_popcount(vcheck);
    double& temp = cache[from][remaining][vcheck];
    if (temp > 0) return temp;
    temp = numeric_limits<double>::max();

    for (int to = 0; to < N; ++to) {
        if (vcheck & (1 << to)) continue;
        temp = min(temp, dp(to, vcheck + (1 << to)) + dist[from][to]);
    }
    return temp;
}

void visit(int from, double length, int vcheck)
{
    if (ret <= length + mst(from, vcheck)) return;

    if (vcheck == (1 << N) - 1) {
        ret = min(ret, length);
        return;
    }

    if (__builtin_popcount(vcheck) + DEPTH >= N) {
        ret = min (ret, length + dp(from, vcheck));
        return;
    }

    for (int to = 0; to < N; ++to) {
        if (from == to || vcheck & (1 << to)) continue;
        vcheck += (1 << to);
        visit(to, length + dist[from][to], vcheck);
        vcheck -= (1 << to);
    }
}

double solve() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j <= DEPTH; ++j) {
            cache[i][j].clear();
        }
    }
    ret = numeric_limits<double>::max();
    for (int from = 0; from < N; ++from) {
        visit(from, 0, (1 << from));
    }
    return ret;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> N;
        read();
        cout.precision(10);
        cout << fixed << solve() << endl;
    }
    return 0;
}
