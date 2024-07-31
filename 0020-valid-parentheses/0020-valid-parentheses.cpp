class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    if (st.top() == '(') {
                        if (c == ')') st.pop();
                        else return false;
                    } else if (st.top() == '[') {
                        if (c == ']') st.pop();
                        else return false;
                    } else if (st.top() == '{') {
                        if (c == '}') st.pop();
                        else return false;
                    }
                }
            }
        }
        return st.size() == 0;
    }
};