class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>odd,even,ans;
        for(auto i:nums)
        {
            if(i&1)odd.push_back(i);
            else even.push_back(i);
        }
        int n=nums.size(),p=0,q=0;
        for(int i=0;i<n;++i)
        {
            if(i&1)ans.push_back(odd[p++]);
            else ans.push_back(even[q++]);
        }
        return ans;
    }
};