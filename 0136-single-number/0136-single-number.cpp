class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int c: nums) {
            x ^= c;
        }
        return x;
    }
};