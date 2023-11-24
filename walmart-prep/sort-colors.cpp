#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int mid = 0, beg = 0, end = n - 1;
    while (mid <= end)
    {
        switch (nums[mid])
        {
        case 0:
            swap(nums[beg++], nums[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(nums[end--], nums[mid]);
            break;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (auto i : nums)
        cout << i << " ";
    return 0;
}