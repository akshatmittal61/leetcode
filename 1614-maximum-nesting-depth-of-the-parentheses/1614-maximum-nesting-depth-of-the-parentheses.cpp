class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, curr = 0;
        stack<char> st;
        for(char c: s) {
            if (c == '(') {
                st.push(c);
                ++curr;
            } else if (c == ')') {
                st.pop();
                --curr;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};