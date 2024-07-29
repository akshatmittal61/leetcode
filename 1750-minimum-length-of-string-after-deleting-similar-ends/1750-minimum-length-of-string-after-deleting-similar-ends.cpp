class Solution {
public:
int minimumLength(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while(l < r) {
            if (s[l] == s[r]) {
                int i = l, j = r;
                while(i < n - 1 && s[i] == s[i + 1])
                    ++i;
                while(j > 0 && s[j] == s[j - 1])
                    --j;
                l = i + 1, r = j - 1;
            } else {
                return max(r - l + 1, 0);
            }
        }
        return max(r - l + 1, 0);
    }
};