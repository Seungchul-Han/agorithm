#include <iostream>
#include <vector>
#include <bitset>
#include <set>
using namespace std;

vector<int> position;
vector<int> value;
int solve(int K)
{
    int ret =0;
    bitset<9> check_pos;
    vector<multiset<int>> max_value(9, multiset<int>());
    for (int i = 0; i < position.size(); ++i) {
        int e = position[i] - 1;
        if (i < K) {
            check_pos.set(e);
            max_value[e].insert(value[i]);
        }
        else {
            int s = position[i-K] - 1;
            auto itr = max_value[s].find(value[i-K]);
            max_value[s].erase(itr);
            max_value[e].insert(value[i]);
            if (max_value[s].empty()) check_pos.reset(s);
            if (max_value[e].size() == 1) check_pos.set(e);
        }
        if (check_pos.all()) {
            int sum = 0;
            for (auto& ms : max_value)
                sum += *ms.rbegin();
            ret = max(ret, sum);
        }
    }
    return ret;
}


int main()
{
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        position.clear(); position.resize(N);
        value.clear(); value.resize(N);
        for (int i = 0;  i < N; ++i)
            cin >> position[i] >> value[i];
        cout << solve(K) << endl;
    }
}
