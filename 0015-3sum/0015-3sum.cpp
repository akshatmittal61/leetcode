class Solution {
public:
    int _(vector<int> v, vector<int> t) {
        int a = v[t[0]];
        int b = v[t[1]];
        int c = v[t[2]];
        if (a + b + c == 0) return 0;
        else if (a + b + c > 0) return 1;
        else return -1;
    }
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int n = v.size();
        int i = 0;
        while ( i < n - 2 ) {
            int low = i + 1, high = n - 1;
            while ( low < high ) {
                int k = _(v, {i, low, high});
                if ( k == 0 ) {
                    ans.push_back({v[i], v[low], v[high]});
                    while( low < high && v[low] == v[low + 1] )
                        ++low;
                    while( high > low && v[high] == v[high - 1] )
                        --high;
                    --high, ++low;
                } else if ( k == 1 ) {
                    do {
                        --high;
                    } while( high > low && v[high] == v[high - 1] );
                } else {
                    do {
                        ++low;
                    } while( low < high && v[low] == v[low + 1] );
                }
            }
            do {
                ++i;
            } while( v[i] == v[i - 1] );
        }
        return ans;
    }
};