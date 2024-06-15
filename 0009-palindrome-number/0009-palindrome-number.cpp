class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 )
            return false;
        else if (x == 0)
            return true;
        else if ( x % 10 == 0 )
            return false;
        int p = 0, num = x;
        while( x > 0 ) {
            if( p > INT_MAX / 10 )
                return false;
            p = (p * 10) + (x % 10);
            x /= 10;
        }
        return num == p;
    }
};