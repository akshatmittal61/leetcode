class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        for( auto c: s ) a[c - 'a']++;
        for( auto c: t ) a[c - 'a']--;
        for( auto i: a ) {
            if( i != 0 )
                return false;
        }
        return true;
    }
};