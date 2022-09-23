class Solution {
public:
    int noOfSetBits(int n)
    {
        int ans=0;
        while(n)
        {
            ++ans;
            n=n&(n-1);
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int>v;
        for(int i=0;i<=n;++i)
            v.push_back(noOfSetBits(i));
        return v;
    }
};