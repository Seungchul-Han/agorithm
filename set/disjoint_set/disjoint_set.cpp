#include <iostream>
#include <vector>

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

void print(DisjointSet& s) {
    vector<int>& p = s.parent;
    vector<int>& c = s.count;
    vector<int>& r = s.rank;
    for (auto i : p)
        cout << i << " ";
    cout << endl;
    for (auto i : c)
        cout << i << " ";
    cout << endl;
    for (auto i : r)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < p.size(); ++i)
        cout << s.find(i) << " ";
    cout << endl;
    cout << endl;
}

int main()
{
    DisjointSet djset(10);
    djset.merge(1, 2); print(djset);
    djset.merge(5, 6); print(djset);
    djset.merge(1, 5); print(djset);

}

