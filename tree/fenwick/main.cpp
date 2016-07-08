#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
public:
    vector<int> tree;

    FenwickTree(int size) {
        tree.resize(size, 0);
    }

    int sum(int i) {
        int result = 0;
        while (i != 0) {
            cout << i << ": " << tree[i] << endl;
            result += tree[i];
            i -= (i & -i);
        }
        return result;
    }

    void update(int i, int diff) {
        while (i < tree.size()) {
            tree[i] += diff;
            i += (i & -i);
        }
    }
};


int main()
{
    vector<int> input{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    FenwickTree t(input.size() + 1);
    for (int i = 0; i < input.size(); ++i) {
        t.update(i+1, input[i]);
    }

    cout << t.sum(10) << endl;
    cout << t.sum(5) << endl;
    cout << t.sum(8) << endl;

    t.update(1, 9);
    t.update(4, 6);

    cout << t.sum(10) << endl;
    cout << t.sum(5) << endl;
    cout << t.sum(8) << endl;
}
