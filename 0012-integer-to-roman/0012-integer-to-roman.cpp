class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int n = num, i = 0;
        map<int, string> m;
        m[1] = "I";
        m[5] = "V";
        m[10] = "X";
        m[50] = "L";
        m[100] = "C";
        m[500] = "D";
        m[1000] = "M";
        while( n != 0 ) {
            string s;
            int p = n % 10;
            if ( p == 0 ) {
            } else if ( m[p * pow(10, i)] != "" ) {
                s = m[ p * pow(10, i) ];
            } else if ( p < 4 ) {
                for(int k = 0; k < p; ++k) {
                    s += m[ pow(10, i) ];
                }
            } else if ( p == 4 ) {
                s += m[ pow(10, i) ];
                s += m[ 5 * pow(10, i) ];
            } else if ( p < 9 ) {
                s += m[ 5 * pow(10, i) ];
                for(int k = 0; k < p - 5; ++k) {
                    s += m[ pow(10, i) ];
                }
            } else if ( p == 9 ) {
                s += m[ pow(10, i) ];
                s += m[ pow(10, i + 1) ];
            }
            ans = s + ans;
            n /= 10;
            ++i;
        }
        return ans;
    }
};