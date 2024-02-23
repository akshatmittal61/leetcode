https://leetcode.com/problems/integer-to-roman

# Approach 1

1. Create a Hash map for storing Roman representation for trivial representation for all numbers.
2. Create a index $k$, which keeps track of how many digits have been iterate over.
3. Start iterating on the number.
4. Start extracting the left-most digit of the number.
5. Get the roman expression for the number from the Hash map.
6. Remove the used number from the complete number.
7. Return the final string.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> m;
        m[1] = "I";
        m[2] = "II";
        m[3] = "III";
        m[4] = "IV";
        m[5] = "V";
        m[6] = "VI";
        m[7] = "VII";
        m[8] = "VIII";
        m[9] = "IX";
        m[10] = "X";
        m[20] = "XX";
        m[30] = "XXX";
        m[40] = "XL";
        m[50] = "L";
        m[60] = "LX";
        m[70] = "LXX";
        m[80] = "LXXX";
        m[90] = "XC";
        m[100] = "C";
        m[200] = "CC";
        m[300] = "CCC";
        m[400] = "CD";
        m[500] = "D";
        m[600] = "DC";
        m[700] = "DCC";
        m[800] = "DCCC";
        m[900] = "CM";
        m[1000] = "M";
        m[2000] = "MM";
        m[3000] = "MMM";
        int k = 1;
        string ans = "";
        int n = num, s = num;
        while (s != 0) {
            int y = pow(10, k);
            int g = n % y;
            string l = m[g];
            l += ans;
            ans = l;
            n -= g;
            ++k;
            s /= 10;
        }
        return ans;
    }
};
```


# Approach 2

1. Create a Hash map to store the roman representation for all the 7 characters.
2. Create a variable $i$, to keep track of how many digits have been traversed.
3. Start iterating on the number from the right most character.
4. If the digit is $0$, skip it.
5. Else if digit is $1$ or $5$ it is stored in the map already. Append it in the answer string in the left most position.
6. Else handle it by repeating the characters.
7. Return the final roman string.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
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
```