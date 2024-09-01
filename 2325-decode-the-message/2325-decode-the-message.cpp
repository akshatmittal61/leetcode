class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> m;
        char cnt = 'a';
        for(char c: key) {
            if (c == ' ') continue;
            if (m.find(c) != m.end()) {
                continue;
            }
            m[c] = cnt;
            ++cnt;
        }
        string ans;
        for(char c: message) {
            if (c == ' ') ans += ' ';
            else ans += m[c];
        }
        return ans;
    }
};