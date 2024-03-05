class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        map<int, int> m;
        for(int x: arr) {
            m[x]++;
        }
        vector<pair<int, int>> counts;
        for(auto it: m) {
            counts.push_back({it.second, it.first});
        }
        sort(counts.begin(), counts.end());
        int cc = counts.size();
        for(int i = 0; i < cc && k > 0; ++i) {
            if( counts[i].first <= k ) {
                m[counts[i].second] -= counts[i].first;
                k -= counts[i].first;
            } else {
                m[counts[i].second] -= k;
                k = 0;
            }
        }
        int ans = 0;
        for(auto it: m) {
            if(it.second > 0)
                ++ans;
        }
        return ans;
    }
};