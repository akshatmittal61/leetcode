#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
    }
    for (int i = 1; i < k; i++)
    {
        pq.pop();
    }
    return pq.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k);
    return 0;
}