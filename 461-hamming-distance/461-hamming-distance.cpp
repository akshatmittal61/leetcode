class Solution {
public:
    int hammingDistance(int x, int y) {
        int n=x^y;
        int ans=0;
        while(n)
        {
            n=n&(n-1);
            ++ans;
        }
        return ans;
    }
};