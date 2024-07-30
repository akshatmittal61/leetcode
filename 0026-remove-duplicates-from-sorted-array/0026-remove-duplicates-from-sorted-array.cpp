class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0, c = 0;
        for(int i = 0; i < n - 1; ++i) {
            while(i < n - 1 && nums[i] == nums[i + 1])
                ++i;
            if (i < n - 1) {
                nums[++k] = nums[i + 1];
            }
        }
        return k + 1;
    }
};