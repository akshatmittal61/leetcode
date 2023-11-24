#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
            i++;
        nums[i] = nums[j];
    }
    return i + 1;
}

int main()
{
    vector<int> nums = {2, 2, 7, 7, 7, 3, 3, 9, 10, 10, 10};
    int ans = removeDuplicates(nums);
    for (int i = 0; i < ans; i++)
        cout << nums[i] << " ";
    return 0;
}