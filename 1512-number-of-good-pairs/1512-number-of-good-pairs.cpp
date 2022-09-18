class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        for(int i=0;i<n-1;++i){
            if(nums[i]==nums[i+1])
            {
                int j=i,k=1;
                while(j<n-1&&nums[j]==nums[j+1])
                {
                    ++k;
                    ++j;
                }
                ans+=(k*(k-1))/2;
                i=j;
            }
        }
        return ans;
    }
};