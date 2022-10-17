class Solution {
public:
    bool checkIfPangram(string s) {
        int a[26]={0};
        for(auto c:s)
            a[c-'a']++;
        for(auto i:a)
            if(i==0)return false;
        return true;
    }
};