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
        set<int> s;
        while ( n != 1 && s.find(n) == s.end() ) {
            int k = getSumOfSquaresOfDigits(n);
            if ( k == 1 )
                return true;
            if ( s.size() > 0 ) {
                if (s.find(k) != s.end())
                    return false;
            }
            s.insert(n);
            n = k;
        }
        return n == 1;
    }
};