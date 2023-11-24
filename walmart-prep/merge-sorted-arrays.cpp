#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    int m = nums1.size(), n = nums2.size();
    for (int i = 0, j = 0; i < m || j < n;)
    {
        if (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        else if (i < m)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 4, 5, 6};
    vector<int> nums2 = {3, 7, 8, 9};
    vector<int> ans = mergeSortedArrays(nums1, nums2);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}