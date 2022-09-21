class Solution {
    public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long SumEven=0;
        for(auto i:nums)
        {
            if(!(i&1))
                SumEven+=i;
        }
        int n=queries.size();
        vector<int>ans;
        for(auto vi:queries)
        {
            if(!(nums[vi[1]]&1))
                SumEven-=nums[vi[1]];
            nums[vi[1]]+=vi[0];
            if(!(nums[vi[1]]&1))
                SumEven+=nums[vi[1]];
            ans.push_back(SumEven);
        }
        return ans;
    }
};