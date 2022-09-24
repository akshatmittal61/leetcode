class Solution {
public:
    int projectionArea(vector<vector<int>>& v) {
        int ans=0,n=v.size();
        for(int i=0;i<n;++i)
        {
            int p=v[i][0],q=v[0][i];
            for(int j=0;j<n;++j)
            {
                p=max(p,v[i][j]);
                q=max(q,v[j][i]);
                ans+=(v[i][j]>0);
            }
            ans+=(p+q);
        }
        return ans;
    }
};