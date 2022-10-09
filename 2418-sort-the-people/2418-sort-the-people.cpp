class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string>m;
        int n=names.size();
        for(int i=0;i<n;++i)
            m[heights[i]]=names[i];
        vector<string>ans;
        for(auto i:m)
            ans.push_back(i.second);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};