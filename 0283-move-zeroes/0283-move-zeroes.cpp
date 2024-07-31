class Solution {
public:
    void reverse(vector<int> &nums, int low, int high) {
        for(int i = low, j = high; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
    }
    void rotate(vector<int>& nums, int low, int high, int k) {
        reverse(nums, low, low + k - 1);
        reverse(nums, low + k, high);
        reverse(nums, low, high);
    }
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int c = i;
            if (nums[i] == 0) {
                while(c < n - 1 && nums[c] == 0) ++c;
                if(c > i) {
                    rotate(nums, i, c, c - i);
                }
            }
        }

    }
};