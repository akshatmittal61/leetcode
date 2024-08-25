class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        for(char c: s) {
            if (c == '(') {
                if (st.size() != 0) ans += '(';
                st.push(c);
            } else {
                st.pop();
                if (st.size() == 0) continue;
                else {
                    ans += ')';
                }
            }
        }
        return ans;
    }
};