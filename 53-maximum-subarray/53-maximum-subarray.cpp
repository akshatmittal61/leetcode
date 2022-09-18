class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    int n = nums.size();
    int curr = 0, Max = nums[0];
    for (auto i : nums)
    {
        curr = max(0, curr);
        curr += i;
        Max = max(Max, curr);
    }
    return Max;
   } 
};