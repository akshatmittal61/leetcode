class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0, end = n - 1;
        while (beg < end) {
            int mid = (beg + end) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) end = mid - 1;
            else beg = mid + 1;
        }
        return -1;
    }
};