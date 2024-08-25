class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.length(), m = typed.length();
        int i = 0, j = 0;
        if (m < n) return false;
        while (i < n && j < m) {
            cout<<i<<' '<<j<<endl;
            if (i > j)
                return false;
            if (name[i] == typed[j]) {
                ++i, ++j;
            } else {
                if (j > 0 && typed[j] == typed[j - 1]) {
                    ++j;
                } else {
                    return false;
                }
            }
        }
        if (i < n) return false;
        while (j < m) {
            cout<<j<<endl;
            if (typed[j] != name[n - 1])
                return false;
            ++j;
        }
        return true;
    }
};