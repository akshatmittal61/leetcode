class Solution {
public:
    string reverseStr(string s, int k) {
        vector<string>v;
        string ans;
        for(int i=0;i<s.length();i+=k)
        {
            string t="";
            for(int j=i;j<min(i+k,(int)s.length());j++)
                t+=s[j];
            v.push_back(t);
        }
        for(int i=0;i<v.size();++i)
        {
            if(!(i&1))reverse(v[i].begin(),v[i].end());
            ans+=v[i];
        }
        return ans;
    }
};