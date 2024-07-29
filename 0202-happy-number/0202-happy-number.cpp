class Solution {
public:
    bool isHappy(int n) {
        cout<<n<<' ';
        if (n <= 0) return false;
        int s = 0;
        while(n != 0) {
            int m = n % 10;
            s += m * m;
            n /= 10;
        }
        cout<<s<<endl;
        if (s == 0) return false;
        if(s == 1 || s == 7) return true;
        if (s > 1 && s <= 9) return false;
        return isHappy(s);
    }
};