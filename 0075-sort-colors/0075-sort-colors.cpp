class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int front = 0, back = n - 1;
        int pointer = 0;
        while( pointer <= back ) {
            if( nums[pointer] == 0 ) {
                swap(nums[front], nums[pointer]);
                ++front;
                ++pointer;
            } else if( nums[pointer] == 2 ) {
                swap(nums[back], nums[pointer]);
                --back;
            } else {
                ++pointer;
            }
        }
    }
};