class Solution {
public:
    int getSumOfSquaresOfDigits (int n) {
        int ans = 0;
        while ( n != 0 ) {
            int k = n % 10;
            ans += (k * k);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        if ( n < 10 )
            return n == 1 || n == 7;
        int k = getSumOfSquaresOfDigits(n);
        return isHappy(k);
    }
};