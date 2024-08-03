class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int n = s.length(), x = 0;
        for(int i = 0; i < n; ++i) {
            if(mp[s[i]] < mp[s[i + 1]]) {
                x += (mp[s[i + 1]] - mp[s[i]]);
                ++i;
            } else {
                x += mp[s[i]];
            }
        }
        return x;
    }
};