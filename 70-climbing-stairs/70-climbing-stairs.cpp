class Solution {
public:
    int fib(int n, vector<int> &v)
    {
        if (n == 0)
            return 0;
        else if (n == 1)
        {
            v[1] = 1;
            return 1;
        }
        else
        {
            if (v[n] == 0)
                v[n] = fib(n - 1, v) + fib(n - 2, v);
            return v[n];
        }
    }
    int climbStairs(int n) {
        vector<int> v(n + 2);
        return fib(n + 1, v);
    }
};