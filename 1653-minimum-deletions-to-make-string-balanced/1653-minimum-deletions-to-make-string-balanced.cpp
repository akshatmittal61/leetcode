class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int al = 0, bl = 0, ar = 0, br = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'a') ++ar;
            if(s[i] == 'b') ++br;
        }
        int ans = ar;
        for(int i = 0; i < n; ++i) {
            ans = min(ans, bl + ar);
            if(s[i] == 'a') {
                ++al;
                --ar;
            } else {
                ++bl;
                --br;
            }
        }
        ans = min(ans, bl + ar);
        return ans;
    }
};