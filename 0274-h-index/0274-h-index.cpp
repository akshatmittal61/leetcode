class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            if( nums[0] >= 1 )
                return 1;
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i = n - 1; i >= 0; --i) {
            if( nums[i] >= n - i )
                continue;
            else {
                // if (i == 0) return min(nums[i], n);
                // if ( nums[i - 1] == 0 )
                //     continue;
                // return min(nums[i - 1], n - i + 1);
                if( i == n - 1 ) return 0;
                return min(nums[i + 1], n - i - 1);
            }
        }
        return min(nums[0], n);
        // 0 1 3 5 6
        // int maxi = nums[n-1];
        // for(int i=1; i<=maxi; i++){
        //     int ans = i;
        //     int num = find()
        //     int papers = n - num;

        //     if(papers >= num) return ans;
        // }
        // return 0;


    }
};