class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        stack<char> st;
        for (auto c: s) {
            if (st.empty()) {
                st.push(c);
            } else {
                if (c == st.top()) {
                    st.push(c);
                } else {
                    st.pop();
                }
                if (st.empty()) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
