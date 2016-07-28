#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int column_lower_bound(vector<vector<int>>& matrix, int begin, int end, int target, int column)
{
    int count = end - begin;
    int step = 0;
    int i = 0;
    while (count > 0) {
        i = begin; step = count/2; i += step;
        if (matrix[i][column] < target) {
            begin = ++i;
            count -= step + 1;
        }
        else count = step;
    }
    return begin;
}

int column_upper_bound(vector<vector<int>>& matrix, int begin, int end, int target, int column)
{
    int count = end - begin;
    int step = 0;
    int i = 0;
    while (count > 0) {
        i = begin; step = count/2; i += step;
        if (!(target < matrix[i][column])) {
            begin = ++i;
            count -= step + 1;
        }
        else count = step;
    }
    return begin;
}

int column_binary_search(vector<vector<int>>& matrix, int begin, int end, int target, int column)
{
    begin = column_lower_bound(matrix, begin, end, target, column);
    return (begin != end && !(target < matrix[begin][column]));
}


int main()
{
    vector<vector<int>> matrix =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int size = matrix[0].size();
    int target = 6;
//    cout << column_lower_bound(matrix, 0, size, target, 0) << endl;
//    cout << column_lower_bound(matrix, 0, size, target, 1) << endl;
//    cout << column_lower_bound(matrix, 0, size, target, 2) << endl;
//
//    cout << column_upper_bound(matrix, 0, size, target, 0) << endl;
//    cout << column_upper_bound(matrix, 0, size, target, 1) << endl;
//    cout << column_upper_bound(matrix, 0, size, target, 2) << endl;
//

    cout << column_binary_search(matrix, 0, size, 0, 0) << endl;
    cout << column_binary_search(matrix, 0, size, 4, 0) << endl;
    cout << column_binary_search(matrix, 0, size, 7, 0) << endl;
    cout << column_binary_search(matrix, 0, size, 10, 0) << endl;

    cout << column_binary_search(matrix, 0, size, 5, 1) << endl;

    cout << column_binary_search(matrix, 0, size, 2, 1) << endl;
    cout << column_binary_search(matrix, 0, size, 9, 2) << endl;
    cout << column_binary_search(matrix, 0, size, 19, 2) << endl;
}
