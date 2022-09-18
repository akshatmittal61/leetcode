class Solution {
public:
    bool check(map<char,int> a,map<char,int> b)
    {
        for(auto i:b)if(i.second>a[i.first])return false;
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<map<char,int>>v;
        for(auto w:words2)
        {
            map<char,int>m;
            for(auto i:w)
                m[i]++;
            v.push_back(m);
        }
        map<char,int>mk;
        for(auto q:v)
        {
            for(auto i:q)
                mk[i.first]=max(mk[i.first],i.second);
        }
        for(auto w:words1)
        {
            map<char,int>m;
            for(auto i:w)m[i]++;
            if(check(m,mk))ans.push_back(w);
        }
        return ans;
    }
};