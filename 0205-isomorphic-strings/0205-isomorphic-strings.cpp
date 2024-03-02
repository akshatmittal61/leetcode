class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        map<char, char> p, q;
        for (int i = 0; i < n; ++i)
        {
            p[s[i]] = t[i];
            q[t[i]] = s[i];
        }
        string a = s, b = t;
        for (int i = 0; i < n; ++i)
        {
            a[i] = p[s[i]];
            b[i] = q[t[i]];
        }
        return a == t && b == s;
    }
};