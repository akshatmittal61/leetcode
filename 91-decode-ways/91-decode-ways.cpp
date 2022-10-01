class Solution
{
    public:
        int cal(int i, string s, vector<int> &dp)
        {
            if (i == -1 || i == 0)
                return 1;

            if (dp[i] != -1)
                return dp[i];
            int w1 = 0, w2 = 0;
            if (s[i] > '0')
                w1 = cal(i - 1, s, dp);
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i]<'7')
                w2 = cal(i - 2, s, dp);
            return dp[i] = w1 + w2;
        }
    int numDecodings(string s)
    {
        int n = s.length();
        if (s == "0")
            return 0;
        if (s[0] == '0')
            return 0;
        vector<int> dp(n + 1, -1);
        return cal(n - 1, s, dp);
    }
};