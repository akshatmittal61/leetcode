class Solution {
    string _(string str) {
        string ans;
        int n = str.length();
        for (int i = 0; i < n; ++i) {
            int c = 1;
            while(i + c < n && str[i + c - 1] == str[i + c]) {
                ++c;
            }
            ans += to_string(c);
            ans += str[i];
            i += c - 1;
        }
        return ans;
    }
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string curr = "1";
        for(int i = 2; i <= n; ++i) {
            cout<<curr<<' ';
            curr = _(curr);
            cout<<curr<<endl;
        }
        return curr;
    }
};