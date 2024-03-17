https://leetcode.com/problems/valid-parentheses

# Approach 1

1. Create stack to compare the most recent bracket to last stored one.
2. Start iterating on the string.
3. If it is an opening bracket, insert in the stack.
4. Else if, check if the recent character is a matching closing bracket for the last bracket stored in the stack.
5. If yes, pop the bracket, it is a valid sub-string.
6. Else push in the string.
7. For a valid string, the stack should be empty at the end, since all the valid sub-string should be popped out.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c: s) {
            if ( c == '(' || c == '[' || c == '{' ) {
                st.push(c);
            } else {
                if (st.size() > 0) {
                    if (c == ')' && st.top() == '(') {
                        st.pop();
                    } else if (c == ']' && st.top() == '[') {
                        st.pop();
                    } else if (c == '}' && st.top() == '{') {
                        st.pop();
                    } else {
                        st.push(c);
                    }
                } else {
                    st.push(c);
                }
            }
        }
        return st.empty();
    }
};
```