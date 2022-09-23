class Solution {
public:
    int countSetBits(int n)
    {
        int ans=0;
        while(n)
        {
            n&=n-1;
            ++ans;
        }
        return ans;
    }
    bool isPrime(int n)
    {
        if(n==0 || n==1) 
            return false;
        for(int i=2;i<=sqrt(n);++i)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;++i)
        {
            ans+=isPrime(countSetBits(i));
        }
        return ans;
    }
};