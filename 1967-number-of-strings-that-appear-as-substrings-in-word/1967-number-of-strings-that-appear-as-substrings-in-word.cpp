class Solution {
public:
    bool check(string a,string b)
    {
        if(a.length()<b.length())return false;
        for(int i=0;i<a.length()-b.length()+1;++i)
        {
            int j=0;
            while(j<b.length() && i+j<a.length() && a[i+j]==b[j])
                ++j;
            if(j==b.length())return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto c:patterns)
            ans+=check(word,c);
        return ans;
    }
};