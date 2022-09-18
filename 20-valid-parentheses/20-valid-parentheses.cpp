class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char>st;
        for(auto i:s)
        {
            if(i=='('||i=='{'||i=='[')st.push(i);
            else if(!st.empty())
            {
                if(i==')')
                {
                    if(st.top()=='(')st.pop();
                    else return false;
                }
                else if(i==']')
                {
                    if(st.top()=='[')st.pop();
                    else return false;
                }
                else if(i=='}')
                {
                    if(st.top()=='{')st.pop();
                    else return false;
                }
            }
            else return false;
        }
        return st.empty();
    }
};