// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#define ll long long int

class Solution {
public:
    int firstBadVersion(int n) {
        ll beg = 0, end = n - 1;
        ll mid = (beg + end) / 2;
        ll ans = mid + 1;
        while (beg <= end)
        {
            mid = (beg + end) / 2;
            if (isBadVersion(mid + 1))
            {
                ans = mid + 1;
                end = mid - 1;
            }
            else
                beg = mid + 1;
            if (beg > end)
                return ans;
        }
        return ans;
    }
};