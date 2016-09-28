#include <iostream>
#include <string>

using namespace std;

string tree;

void shift(int start, int end, int num) {
    while(num--) {
        char temp = tree[end - 1];
        int index = end -2;
        while(index >= start) {
            tree[index + 1] = tree[index];
            --index;
        }
        tree[start] = temp;
    }
}

int swap(int index) {
    if (tree[index] == 'w' || tree[index] == 'b')
        return 1;

    int start = ++index;
    int upperLeft = swap(index);
    index += upperLeft;
    int upperRight = swap(index);
    index += upperRight;
    int lowerLeft = swap(index);
    index += lowerLeft;
    int lowerRight = swap(index);
    index += lowerRight;

    int total = upperLeft + upperRight + lowerLeft + lowerRight;
    int end = start + total;
    int num = lowerLeft + lowerRight;
    shift(start, end, num);
    return total + 1;
}

int main() {
    int numOfCase;
    cin >> numOfCase;

    while(numOfCase) {
        cin >> tree;
        swap(0);
        cout << tree << endl;
        --numOfCase;
    }

    return 0;
}

