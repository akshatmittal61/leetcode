class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) {
            return left;
        }
        if (left <=0 && right >= 0) {
            return 0;
        }
        double l_log = log2(left);
        double r_log = log2(right);
        int log_left = ceil(l_log);
        int log_right = floor(r_log);
        if ( l_log < log_left && log_left <= r_log )
            return 0;
        if ( l_log == log_left ) {
            if( log_right > log_left ) {
                return 0;
            } else {
                return left;
            }
        }
        long long int ans = left;
        for (long long int i = left + 1; i <= right; ++i) {
            if ( ans == 0 )
                return 0;
            ans &= i;
        }
        return ans;
    }
};