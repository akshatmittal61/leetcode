class Solution {
public:
    int countSetBits(int n)
    {
        int ans=0;
        while(n)
        {
            n=n&(n-1);
            ++ans;
        }
        return ans;
    }
    int findComplement(int num) {
        long long int n=log2(num);
        if(countSetBits(num)==1)return num-1;
        long long int c=pow(2,n+1);
        return c-num-1;
    }
};