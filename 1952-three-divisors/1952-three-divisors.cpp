class Solution {
public:
    bool isPrime(int n)
    {
        for(int i=2;i<=sqrt(n);++i)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    bool isThree(int n) {
        if(n==1 || isPrime(n))return false;
        int k=0;
        for(int i=2;i<n;++i)
        {
            k+=(n%i==0);
            if(k>1)
                return false;
        }
        return k==1;
    }
};