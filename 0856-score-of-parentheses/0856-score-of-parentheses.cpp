class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int ans = 0, d = 0;
        for(auto c: s) {
            if (c == '(') {
                ++d;
            } else {
                if (st.top() == '(') {
                    ans += 1 << (d - 1);
                }
                --d;
            }
            st.push(c);
        }
        return ans;
    }
};