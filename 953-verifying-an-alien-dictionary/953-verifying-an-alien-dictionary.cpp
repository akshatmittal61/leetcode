class Solution {
public:
    bool isLex(map<char,int>m,string a,string b)
    {
        int n=min(a.length(),b.length());
        bool same=true;
        for(int i=0;i<n;++i)
        {
            if(m[a[i]]<m[b[i]])return true;
            else if(a[i]==b[i])continue;
            else return false;
            if(same && a[i]!=b[i])same=false;
        }
        if(same)
        {
            if(a.length()>b.length())
                return false;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        map<char,int>m;
        for(int i=0;i<order.length();++i)
            m[order[i]]=i+1;
        for(int i=0;i<n-1;++i)
        {
            if(!isLex(m,words[i],words[i+1]))
                return false;
        }
        return true;
    }
};