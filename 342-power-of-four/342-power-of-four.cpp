class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        if(n!=1 && n%4!=0)return false;
        while(!(n%4))
        {
            n/=4;
            if(n!=1 && n%4!=0)return false;
        }
        return true;
    }
};