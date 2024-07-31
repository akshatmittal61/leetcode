class Solution {
public:
    void reverse(vector<int> &nums, int low, int high) {
        for(int i = low, j = high; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};