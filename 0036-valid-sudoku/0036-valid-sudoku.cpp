class Solution {
    bool isValid(vector<char> v) {
        vector<int> a(9, 0);
        for(char x: v) {
            if(x == '.') continue;
            if(a[x - '1'] > 0) return false;
            a[x - '1']++;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check for rows
        for (int i = 0; i < 9; ++i) {
            if (!isValid(board[i]))
                return false;
        }
        // check for columns
        for (int i = 0; i < 9; ++i) {
            vector<char> v;
            for (int j = 0; j < 9; ++j) {
                v.push_back(board[j][i]);
            }
            if (!isValid(v))
                return false;
        }
        // check for box
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                vector<char> v;
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        v.push_back(board[(i * 3) + k][(j * 3) + l]);
                    }
                }
                if(!isValid(v))
                    return false;
            }
        }
        return true;
    }
};