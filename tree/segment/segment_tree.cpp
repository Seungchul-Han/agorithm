#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SegmentTree {
public:
    vector<int> tree;
    int node_count;
    SegmentTree(int N): node_count(N) {
        int h = (int)ceil(log2(node_count));
        int tree_size = (1 << (h+1));
        tree.resize(tree_size, 0);
    }
    int makeTree(vector<int>& input, int node, int start, int end) {
        if (start == end)
            return tree[node] = input[start];
        else
            return tree[node] = makeTree(input, node * 2, start, (start + end)/2) +
                makeTree(input, node * 2 + 1, (start + end)/2 + 1, end);
    }
    int sum(int left, int right) {
        return sum(1, 0, node_count - 1, left - 1, right - 1);
    }

    void update(int target, int diff) {
        update(1, 0, node_count - 1, target - 1, diff);
    }

private:
    int sum(int node, int start, int end, int left, int right) {
        if (right < start || end < left) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[node];
        }
        return sum(node * 2, start, (start + end)/2, left, right) +
            sum(node * 2 + 1, (start + end)/2 + 1, end, left, right);
    }

    void update(int node, int start, int end, int target, int diff) {
        if (target < start || end < target) {
            return;
        }
        tree[node] += diff;
        if (start != end) {
            update(node * 2, start, (start + end)/2, target, diff);
            update(node * 2 + 1, (start + end)/2 + 1, end, target, diff);
        }
    }

};


int main()
{
    vector<int> input{ 1,2,3,4,5,6,7,8,9,10};

    int N = input.size();
    SegmentTree t(N);
    t.makeTree(input, 1, 0, N - 1);

    cout << t.sum(1, 10) << endl;
    cout << t.sum(1, 5) << endl;
    cout << t.sum(1, 8) << endl;
    cout << t.sum(6, 8) << endl;

    t.update(1, 9);
    t.update(4, 6);

    cout << t.sum(1, 10) << endl;
    cout << t.sum(1, 5) << endl;
    cout << t.sum(1, 8) << endl;
    cout << t.sum(6, 8) << endl;
}
