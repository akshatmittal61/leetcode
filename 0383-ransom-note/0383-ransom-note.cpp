class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26, 0);
        for (auto c: magazine) v[c - 'a']++;
        for (auto c: ransomNote) v[c - 'a']--;
        for (auto x: v) {
            if (x < 0)
                return false;
        }
        return true;
    }
};