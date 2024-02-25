class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int n = v.size();
        for (int i = 0; i < n - 2; ++i ) {
            int low = i + 1, high = n - 1;
            while ( low < high ) {
                int l = v[i] + v[low] + v[high];
                int k = 0;
                if ( l > 0 ) k = 1;
                else if ( l < 0 ) k = -1;
                if ( k == 0 ) {
                    ans.push_back({v[i], v[low], v[high]});
                    while( high > low && v[high] == v[high - 1] ) --high;
                    while( low < high && v[low] == v[low + 1] ) ++low;
                    ++low, --high;
                } else if ( k == 1 ) {
                    --high;
                } else {
                    ++low;
                }
            }
            while( i < n - 1 && v[i] == v[i + 1] )
                ++i;
        }
        return ans;
    }
};