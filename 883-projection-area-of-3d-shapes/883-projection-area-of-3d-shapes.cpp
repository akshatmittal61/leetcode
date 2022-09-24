class Solution {
public:
    int projectionArea(vector<vector<int>>& v) {
        int ans=0;
        for(auto r:v)
        {
            for(auto i:r)
                ans+=(i>0);
        }
        int n=v.size();
        for(int i=0;i<n;++i)
        {
            int l=v[i][0];
            for(int j=0;j<n;++j)
                l=max(l,v[i][j]);
            ans+=l;
        }
        for(int i=0;i<n;++i)
        {
            int l=v[0][i];
            for(int j=0;j<n;++j)
                l=max(l,v[j][i]);
            ans+=l;
        }
        return ans;
    }
};