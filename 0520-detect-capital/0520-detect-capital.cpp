class Solution
{
    bool _(char c)
    {
        return c >= 'A' && c <= 'Z';
    }
    char Case(char c)
    {
        return c >= 'A' && c <= 'Z' ? 'u' : 'l';
    }
    public:
        bool detectCapitalUse(string word)
        {
            int n = word.length();
            if (n == 1) return true;
            if (_(word[0]))
            {
                for (int i = 1; i < n - 1; ++i)
                {
                    if (Case(word[i]) != Case(word[i + 1]))
                        return false;
                }
            }
            else
            {
                for (int i = 1; i < n; ++i)
                {
                    if (_(word[i]))
                        return false;
                }
            }
            return true;
        }
};