#include <iostream>
#include <vector>
using namespace std;

// [p, q)
int partition(vector<int>& nums, int p, int q)
{
    int& pivot = nums[p];
    int j = p;
    for (int i = p + 1; i < q; ++i) {
        if (nums[i] <= pivot) {
            swap(nums[i], nums[++j]);
        }
    }
    swap(pivot, nums[j]);
    return j;
}

int qsort(vector<int>& nums, int p, int q)
{
    if (p < q) {
        int r = partition(nums, p, q);
        qsort(nums, p, r);
        qsort(nums, r + 1, q);
    }
}

int main()
{
    vector<int> nums{ 1, 3, 5, 7, 2, 4, 6, 8 };
    vector<int> nums1{ 7, 2, 4, 6, 8, 1, 3, 5 };

    qsort(nums, 0, nums.size());
    qsort(nums1, 0, nums1.size());


    for (auto i : nums) cout << i << ", "; cout << endl;
    for (auto i : nums1) cout << i << ", "; cout << endl;
}
