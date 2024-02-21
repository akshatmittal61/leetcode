class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                continue;
            } else {
                string f;
                while( i < n && s[i] != ' ' ) {
                    f += s[i++];
                }
                v.push_back(f);
            }
        }
        string ans;
        int l = v.size();
        for(int i = l - 1; i >= 0; --i) {
            ans += v[i];
            if ( i != 0 ) {
                ans += ' ';
            }
        }
        return ans;
    }
};