class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos;
        vector<int>neg;
        for(auto i:nums)
        {
            if(i<0)neg.push_back(i);
            else pos.push_back(i);
        }
        vector<int>ans;
        for(int i=0;i<n/2;++i)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};