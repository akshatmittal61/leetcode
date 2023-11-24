#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int> &nums, int k)
{
    vector<int> v(nums.size());
    for (int i = 0; i < nums.size(); i++)
        v[(k + i) % nums.size()] = nums[i];
    nums = v;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotateArray(nums, k);
    for (auto i : nums)
        cout << i << " ";
    return 0;
}