class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(string s: strs) {
            string a = s;
            sort(a.begin(), a.end());
            if(m.find(a) != m.end()) {
                m[a].push_back(s);
            } else {
                m[a] = {s};
            }
        }
        vector<vector<string>> v;
        for(auto t: m) {
            v.push_back(t.second);
        }
        return v;
    }
};