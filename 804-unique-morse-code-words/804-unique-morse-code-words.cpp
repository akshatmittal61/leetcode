class Solution {
public:
    string morseCodes[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string transform(string s)
    {
        string ans;
        for(auto i:s)ans+=morseCodes[i-'a'];
        return ans;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>s;
        for(auto i:words)s.insert(transform(i));
        return s.size();
    }
};