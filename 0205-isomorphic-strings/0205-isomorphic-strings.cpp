class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m, p;
        int n = s.length();
        for(int i = 0;i < n; ++i) {
            if(m.find(s[i]) == m.end()) {
                m[s[i]] = t[i];
            } else {
                if(m[s[i]] != t[i]) return false;
            }
            if(p.find(t[i]) == p.end()) {
                p[t[i]] = s[i];
            } else {
                if(p[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};