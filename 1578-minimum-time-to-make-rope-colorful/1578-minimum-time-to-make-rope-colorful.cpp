class Solution {
public:
    int minCost(string s, vector<int>& t) {
        int total_sum = 0, cur_sum = t[0], maxx = t[0];
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i - 1] == s[i])
            {
                cur_sum += t[i];
                maxx = max(maxx, t[i]);
            }
            else
            {
                total_sum += cur_sum - maxx;
                maxx = t[i];
                cur_sum = t[i];
            }
        }
        total_sum += cur_sum - maxx;
        return total_sum;
    }
};