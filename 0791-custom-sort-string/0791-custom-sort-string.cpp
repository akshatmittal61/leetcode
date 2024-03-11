class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        map<int, int> m;
        for (char c: s) {
            m[c]++;
        }
        for(char c: order) {
            if ( m.find(c) != m.end() ) {
                ans.append(m[c], c);
            }
            m.erase(c);
        }
        for(auto it: m) {
            ans.append(it.second, it.first);
        }
        return ans;
    }
};