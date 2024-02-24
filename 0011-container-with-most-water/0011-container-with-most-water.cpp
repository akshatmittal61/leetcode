class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        int ans = INT_MIN;
        int low = 0, high = n - 1;
        whlie ( low < high ) {
            int k = (high - low) * min(v[low], v[high]);
            if ( k > ans )
                ans = k;
            if ( v[low] > v[high] )
                --high;
            else
                ++low;
        }
        return ans;
    }
};