class Solution
{
    vector<string> split(string s, char c)
    {
        int n = s.length();
        vector<string> ans;
        for (int i = 0; i < n; ++i)
        {
            string h = "";
            for (int j = i; j < n; ++j)
            {
                if (s[j] == c || j == n - 1)
                {
                    i = j;
                    if (j == n - 1)
                        h += s[n - 1];
                    break;
                }
                else h += s[j];
            }
            ans.push_back(h);
        }
        return ans;
    }
    string join(vector<string> v, char c)
    {
        string ans = "";
        int n = v.size();
        for (int i = 0; i < n; ++i)
        {
            ans += v[i];
            if (i != n - 1) ans += c;
        }
        return ans;
    }
    bool isCap(char c)
    {
        return c >= 'A' && c <= 'Z';
    }
    bool isSml(char c)
    {
        return c >= 'a' && c <= 'z';
    }
    string filter(string s)
    {
        int n = s.length();
        if (n == 1 || n == 2)
        {
            for (int i = 0; i < n; ++i)
            {
                if (isCap(s[i]))
                    s[i] = s[i] - 'A' + 'a';
            }
            return s;
        }
        if (!isCap(s[0]))
            s[0] = s[0] - 'a' + 'A';
        for (int i = 1; i < n; ++i)
        {
            if (isCap(s[i]))
                s[i] = s[i] - 'A' + 'a';
        }
        return s;
    }
    public:
        string capitalizeTitle(string title)
        {
            vector<string> v = split(title, ' ');
            int s = v.size();
            for (int i = 0; i < s; ++i)
                v[i] = filter(v[i]);
            string ans = join(v, ' ');
            return ans;
        }
};