class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        map<int, char> mp;
        mp[1] = 'I';
        mp[5] = 'V';
        mp[10] = 'X';
        mp[50] = 'L';
        mp[100] = 'C';
        mp[500] = 'D';
        mp[1000] = 'M';
        int n = num, x = 0;
        while (n != 0) {
            int m = n % 10;
            int y = pow(10, x);
            string c;
            if (m == 0) {
                c = "";
            } else if (m >= 1 && m <= 3) {
                for (int i = 1; i <= m; ++i) {
                    c += mp[y];
                }
            } else if (m == 4) {
                c += mp[1 * y];
                c += mp[5 * y];
            } else if (m == 5) {
                c += mp[5 * y];
            } else if (m >= 6 && m <= 8) {
                c += mp[5 * y];
                for (int i = 1; i <= m - 5; ++i) {
                    c += mp[y];
                }
            } else if (m == 9) {
                c += mp[y];
                c += mp[10 * y];
            }
            ans = c + ans;
            n /= 10;
            ++x;
        }
        return ans;
    }
};