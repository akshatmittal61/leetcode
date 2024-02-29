class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for ( int i = 0; i < 9; ++i ) {
            vector<int> v(9, 0);
            for ( int j = 0; j < 9; ++j ) {
                if ( board[i][j] == '.' ) {
                    continue;
                }
                if ( v[board[i][j] - '0' - 1] >= 1 ) {
                    return false;
                }
                v[board[i][j] - '0' - 1]++;
            }
        }
        for ( int i = 0; i < 9; ++i ) {
            vector<int> v(9, 0);
            for ( int j = 0; j < 9; ++j ) {
                if ( board[j][i] == '.' ) {
                    continue;
                }
                if ( v[board[j][i] - '0' - 1] >= 1 ) {
                    return false;
                }
                v[board[j][i] - '0' - 1]++;
            }
        }
        for ( int i = 0; i < 9; i += 3 ) {
            for ( int j = 0; j < 9; j += 3 ) {
                vector<int> v(9, 0);
                for ( int I = i; I < i + 3; ++I ) {
                    for ( int J = j; J < j + 3; ++J ) {
                        if ( board[I][J] == '.' ) {
                            continue;
                        }
                        if ( v[board[I][J] - '0' - 1] >= 1 ) {
                            return false;
                        }
                        v[board[I][J] - '0' - 1]++;
                    } 
                }
            }
        }
        return true;
    }
};