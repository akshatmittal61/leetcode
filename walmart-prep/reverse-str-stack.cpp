#include <bits/stdc++.h>
using namespace std;

string reverseStrByStack(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
        st.push(s[i]);
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    string s = "Hello";
    cout << reverseStrByStack(s);
    return 0;
}