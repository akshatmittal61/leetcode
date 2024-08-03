class Solution {
    vector<string> getWords (string s) {
        int n = s.length();
        vector<string> ans;
        string curr;
        for(int i = 0; i < n; ++i) {
            if(s[i] == ' ') {
                if (curr.length() > 0) {
                    ans.push_back(curr);
                    curr = "";
                }
            } else {
                curr += s[i];
            }
        }
        if(curr.length() > 0) ans.push_back(curr);
        return ans;
    }
public:
    string reverseWords(string s) {
        vector<string> words = getWords(s);
        string ans;
        int n = words.size();
        for(int i = n - 1; i >= 0; --i) {
            ans += words[i];
            if(i != 0) ans += " ";
        }
        return ans;
    }
};