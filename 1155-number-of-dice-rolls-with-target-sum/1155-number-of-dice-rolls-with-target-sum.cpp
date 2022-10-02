class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        long long mod= 1e9+7;
        dp[0][0] = 1;
        
        for(int i=1; i<=target; i++) // i=sum
        {
            for(int j=1; j<=n; j++) // j=dice
            {
                for(int val=1; val<=k; val++) // checking values of the current dice
                {
                    int currVal = 0;
                    if((i-val) >= 0)
                        currVal = dp[j-1][i-val];
                    
                    dp[j][i] = (dp[j][i] + currVal) % mod;
                }
            }
        }
        return dp[n][target];
    }
};