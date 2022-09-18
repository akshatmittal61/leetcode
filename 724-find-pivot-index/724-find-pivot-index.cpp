class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int ls=0,rs=0;
        for(int i=1;i<n;++i)rs+=nums[i];
        if(ls==rs)return 0;
        for(int i=0;i<n-1;++i){
            ls+=nums[i];
            rs-=nums[i+1];
            if(ls==rs)return i+1;
        }
        ls=0,rs=0;
        for(int i=0;i<n-1;++i)ls+=nums[i];
        if(ls==rs)return n-1;
        return -1;
    }
};