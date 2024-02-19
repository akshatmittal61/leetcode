class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s[0]==' ')
            s.erase(s.begin());
        while(s[s.length()-1]==' ')
            s.erase(s.end()-1);
        for(int i=0;i<s.length()-1;++i)
        {
            if(s[i]==s[i+1]&&s[i]==' '){
                s.erase(s.begin()+i);
                --i;
            }
        }
        int k=-1;
        for(int i=0;i<s.length();++i)
            if(s[i]==' ')k=i;
        if(k==-1)return s.length();
        else return s.length()-k-1;
    }
};