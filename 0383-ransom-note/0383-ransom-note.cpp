class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r(26, 0);
        vector<int> m(26, 0);
        for (auto c: ransomNote) {
            r[c-'a']++;
        }
        for (auto c: magazine) {
            m[c-'a']++;
        }
        for ( int i = 0; i < 26; ++i ) {
            if ( m[i] < r[i] )
                return false;
        }
        return true;
    }
};