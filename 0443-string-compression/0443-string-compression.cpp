class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string s;
        for(int i = 0; i < n; ++i) {
            int c = 1;
            s += chars[i];
            cout<<i<<' '<<chars[i]<<' ';
            while(i < n - 1 && chars[i] == chars[i + 1]) {
                ++c, ++i;
            }
            cout<<c<<' ';
            if (c != 1) {
                s += to_string(c);
            }
            cout<<s<<endl;
        }
        int ans = s.length();
        cout<<s;
        for(int i = 0; i < ans; ++i) {
            chars[i] = s[i];
        }
        return ans;
    }
};