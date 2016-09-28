#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<pair<int, int>> fset; // idx, distance
set<pair<int, int>> mset; // distance, idx
int prog, prog_max;

void update_mset()
{
    int dist = fset.end()->first < mset.begin()->second ? prog_max :
        fset.lower_bound(make_pair(mset.begin()->second, 0))->second + prog;
    int idx = mset.begin()->second;
    mset.erase(mset.begin());
    mset.insert(make_pair(dist, idx));
}

int solve(string& fan, string& mem)
{
    prog_max = fan.size() - mem.size() + 1;
    fset.clear(); mset.clear();
    for (int i = fan.size() - 1; i >= 0; i--) {
        if (fan[i] == 'M')
            fset.insert(make_pair(i, fset.empty() ? prog_max : i - fset.begin()->first));
        if (i < mem.size() && mem[i] == 'M')
            mset.insert(make_pair(fset.empty() ? prog_max : i - fset.begin()->first, i));
    }

    int min = mset.empty() ? prog_max : mset.begin()->first, cnt = 0;
    while ((prog += min) < prog_max) {
        do { update_mset(); } while (mset.begin()->first == min);
        min = mset.begin()->first; cnt++;
    }
    return prog_max - cnt;
}

int main()
{

    int T; cin >> T;
    while (T--) {
        string mem, fan;
        cin >> mem >> fan;
        prog = 0;
        cout << solve(fan, mem) << endl;
    }
}
