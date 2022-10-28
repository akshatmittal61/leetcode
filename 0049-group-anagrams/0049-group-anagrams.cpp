class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        for(auto s:strs)
        {
            string t=s;
            sort(t.begin(),t.end());
            m[t].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto e:m)
        {
            vector<string>r;
            for(auto s:e.second)
                r.push_back(s);
            ans.push_back(r);
        }
        return ans;
    }
};