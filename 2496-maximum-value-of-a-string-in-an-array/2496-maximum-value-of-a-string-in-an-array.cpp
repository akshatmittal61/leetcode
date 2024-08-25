class Solution {
    char type(string s) {
        for(auto c: s) {
            if (
                (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z')
            )
                return 'a';
        }
        return 'n';
    }
    int score (string s) {
        if (type(s) == 'n')
            return stoi(s);
        else
            return s.length();
    }
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for(string s: strs) {
            int l = score(s);
            if (l > ans)
                ans = l;
        }
        return ans;
    }
};