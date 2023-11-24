#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    map<int, int> m;
    for (auto i : nums)
    {
        if (m.find(i) != m.end())
            return i;
        m[i]++;
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << findDuplicate(nums);
    return 0;
}