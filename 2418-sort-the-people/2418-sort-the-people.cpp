class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> m;
        int n = names.size();
        for (int i = 0; i < n; ++i) {
            m[heights[i]] = names[i];
        }
        int i = 0;
        for (auto x: m) {
            names[i++] = x.second;
        }
        reverse(names.begin(), names.end());
        return names;
    }
};