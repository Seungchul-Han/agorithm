#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int T = 0;
int N = 0;

void input(vector<int>& h)
{
    for (int i=0; i<N; ++i) {
        cin >> h[i];
    }
}

int solve(vector<int>& h)
{
    int ans = 0;
    stack<int> st; st.push(-1);
    for (int i=0; i<h.size(); ++i) {
        while (!st.empty() && h[st.top()] > h[i]) {
            int height = h[st.top()];
            st.pop();
            if (!st.empty())
                ans = max(ans, (i - st.top() - 1) * height);
        }
        st.push(i);
    }

    while(!st.empty()) {
        int height = h[st.top()];
        st.pop();
        int end = h.size();
        if (!st.empty())
            ans = max(ans, (end - st.top() - 1) * height);
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
        cout << solve(h) << endl;
    }
}
