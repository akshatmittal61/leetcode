class Solution {
    int peak(vector<int>& nums, int beg, int end) {
        int n = nums.size();
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if (
                (mid == 0 || nums[mid - 1] < nums[mid]) &&
                (mid == n - 1 || nums[mid + 1] < nums[mid])
            ) return mid;
            else if (nums[mid + 1] > nums[mid])
                return peak(nums, mid + 1, end);
            else return peak(nums, beg, mid - 1);
        }
        return -1;
    }
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return peak(nums, 0 , n - 1);
    }
};